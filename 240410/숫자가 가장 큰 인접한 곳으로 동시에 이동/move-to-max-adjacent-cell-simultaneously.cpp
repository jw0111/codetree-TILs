#include <iostream>
#include <cstring>
using namespace std;

int board[21][21]; // 원래 보드
int marbles[21][21]; // 구슬 위치
int temp[21][21]; // 옮기는 동안 사용할 임시 배열

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m, t;
int ans = 0;

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << marbles[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void move(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(marbles[i][j]){
                int d = 0; // 이동할 방향
                int nx, ny;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                        continue;
                    if(board[nx][ny] > board[i + dx[d]][j + dy[d]]){
                        d = dir; // 더 큰 숫자라면 d 변경
                    }
                }
                nx = i + dx[d];
                ny = j + dy[d];
                ++temp[nx][ny];
            }
        }
    }

    memset(marbles, 0, sizeof(marbles));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(temp[i][j] == 1){
                marbles[i][j] = 1;
            }
        }
    }
    memset(temp, 0, sizeof(temp));
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }

    for(int i = 0; i < m; i++){
        int r, c;
        cin >> r >> c;
        marbles[r][c] = 1;
    }

    for(int i = 0; i < t; i++){
        move();
    }

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(marbles[i][j] == 1)
                ++ans;
        }
    }

    cout << ans;

    
    return 0;
}