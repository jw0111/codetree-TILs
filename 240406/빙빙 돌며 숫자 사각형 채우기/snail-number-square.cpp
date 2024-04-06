#include <iostream>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int x = 0, y = 0;
int dir = 0;
int board[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++){
        //cout << x << " " << y << '\n';
        board[x][y] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != 0){
           dir = (dir + 1) % 4;
           nx = x + dx[dir];
           ny = y + dy[dir];
        }

        x = nx;
        y = ny;

 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}