#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int r, c;
int board[101][101];
int temp[101][101];
bool isExploded[101][101];
int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << isExploded[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void explode(){
    for(int t = 0; t <= m; t++){
        memset(isExploded, false, sizeof(isExploded)); // isExploded 초기화
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(board[i][j] && !isExploded[i][j]){
                    for(int dir = 0; dir < 4; dir++){
                        int dist = floor(pow(2, t - 1));
                        int nx = i + dx[dir] * dist;
                        int ny = j + dy[dir] * dist;
                        //cout << "dist : " <<  dist << '\n';
                        if(nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny])
                            continue;
                        board[nx][ny] = 1;
                        isExploded[nx][ny] = true;
                        isExploded[i][j] = true;
                    }
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> r >> c;

    board[r][c] = 1;
    explode();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j])
                ++ans;
        }
    }

    cout << ans;

    return 0;
}