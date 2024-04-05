#include <iostream>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[101][101];
int n;

int cntOne(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(x < 0 || x >= n || y < 0 || y >= n)
            continue;
        
        if(board[nx][ny] == 1)
            ++cnt;
    }
    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cntOne(i, j) >= 3)
                ++ans;
        }
    }
    cout << ans;
    return 0;
}