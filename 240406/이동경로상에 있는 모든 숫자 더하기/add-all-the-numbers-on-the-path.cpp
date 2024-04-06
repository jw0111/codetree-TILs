#include <iostream>
#include <string>
using namespace std;

int N, T;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int x, y;
int dir = 0;
int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> T;
    x = N / 2, y = N / 2;
    string cmd;
    cin >> cmd;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    ans += board[x][y];
    for(int i = 0; i < cmd.length(); i++){
        if(cmd[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        else if(cmd[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else if(cmd[i] == 'F'){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            x = nx; y = ny;
            ans += board[x][y];
        }
    }

    cout << ans;
    return 0;
}