#include <iostream>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[101][101];
int N, M;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        board[x][y] = 1;

        for(int j = 0; j < 4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx <= 0 || nx > N || ny <= 0 || ny >= M)
                continue;
            if(board[nx][ny] == 1)
                ++cnt;
        }
        if(cnt == 3)
            cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}