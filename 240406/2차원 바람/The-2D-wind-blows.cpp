#include <iostream>
using namespace std;

int board[101][101];
int backup[101][101];
int N, M, Q;
int r1, c1, r2, c2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void rotate(int r1, int c1, int r2, int c2) {
    int temp = board[r1][c1];
    for(int row = r1; row < r2; row++)
        board[row][c1] = board[row + 1][c1];
    
    for(int col = c1; col < c2; col++)
        board[r2][col] = board[r2][col + 1];

    for(int row = r2; row > r1; row--)
        board[row][c2] = board[row - 1][c2];
    
    for(int col = c2; col > c1; col--)
        board[r1][col] = board[r1][col - 1];
    board[r1][c1 + 1] = temp;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }

    for(int time = 0; time < Q; time++){
        cin >> r1 >> c1 >> r2 >> c2;
        rotate(r1, c1, r2, c2);

        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                int cnt = 1;
                int sum = board[i][j];
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx <= 0 || nx > N || ny <= 0 || ny > M)
                        continue;
                    sum += board[nx][ny];
                    cnt++;
                }
                backup[i][j] = sum / cnt;
            }
        }

        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                board[i][j] = backup[i][j];
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << board[i][j] << " ";
        }
        cout<< '\n';
    }

    return 0;
}