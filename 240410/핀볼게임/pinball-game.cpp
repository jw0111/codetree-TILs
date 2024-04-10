#include <iostream>
using namespace std;

int board[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// 반시계 방향, E:0, S:1, W:2, N:3
int N, K;
int dir = 0;
int x = 0, y = 0;
int ans = 0;

void findStart(int K){
    for(int i = 1; i < K; i++){ // 테두리 돌면서 시작 지점 찾기
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            dir = (dir + 1) % 4;
        else {
            x = nx;
            y = ny;
        }
    }
    dir = (dir + 1) % 4;
}

int shoot(){
    int time = 1;
    while(true){
        if(x < 0 || x >= N || y < 0 || y >= N){
            break;
        }
        if(board[x][y] == 1){ // 1 = /
            if(dir % 2 != 0) { // N or S
                dir = (dir + 1) % 4; 
            }
            else
                dir = (dir + 3) % 4; // 시계방향
        }
        else if(board[x][y] == 2) { // 2 = \ '
            if(dir % 2 != 0){
                dir = (dir + 3) % 4;
            }
            else
                dir = (dir + 1) % 4;
            //cout << "dir : " << dir << '\n';
        }
        x += dx[dir];
        y += dy[dir];
        //cout << x << " " << y << '\n';
        ++time;
    }
    return time;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= 4 * N; i++){
        dir = 0;
        x = 0, y = 0;
        findStart(i);
        ans = max(ans, shoot());
    }

    cout << ans;

    return 0;
}