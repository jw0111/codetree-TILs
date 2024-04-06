#include <iostream>
#include <cstring>
using namespace std;

int board[201][201];
int r, c, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int temp[201][201];

void explode(){
    int dist = board[r][c];
    for(int i = 0; i < dist; i++){
        for(int j = 0; j < 4; j++){
            int nx = r + dx[j] * i;
            int ny = c + dy[j] * i;

            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
            continue;
            board[nx][ny] = 0;
            if(i == 0) break;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
    cin >> r >> c;

    explode();
    int cnt = n;

    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            if(board[j][i] != 0){
                temp[cnt][i] = board[j][i];
                --cnt;
            }
        }
        cnt = n;
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}