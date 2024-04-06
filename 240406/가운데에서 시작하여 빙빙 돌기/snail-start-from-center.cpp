#include <iostream>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n;
int board[101][101];
int x, y;
int dir = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    x = n / 2, y = n / 2;

    for(int i = 1; i <= n * n; i++){
        board[x][y] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] != 0){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];

        }
        x = nx;
        y = ny;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}