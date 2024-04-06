#include <iostream>
using namespace std;

int board[101][101];
int backup[101][101];
int N, M, Q;
int r1, c1, r2, c2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void copy(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            backup[i][j] = board[i][j];
    }
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
        int tmp1 = board[r1 + 1][c1];
        int tmp2 = board[r2][c2];
        int tmp3 = board[r2][c1];
        int tmp4 = board[r1][c2];

        for(int i = c2; i > c1; i--){
            board[r1][i] = board[r1][i - 1];
        }
        for(int i = r2; i > r1; i--){
            board[i][c2] = board[i - 1][c2];
        }
        board[r1 + 1][c2] = tmp4;

        for(int i = c1; i < c2; i++){
            board[r2][i] = board[r2][i + 1];
        }
        board[r2][c2 - 1] = tmp2;
        board[r2 - 1][c1] = tmp3;
        for(int i = r1; i < r2 - 1; i++){
            board[i][c1] = board[i + 1][c1];
        }
        board[r1][c1] = tmp1;
        copy();

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

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++)
                board[i][j] = backup[i][j];
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