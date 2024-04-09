#include <iostream>
using namespace std;

int N;
int x, y;
char board[101][101];
int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}; // 시계방향(오, 아래, 왼, 위)
int dir = 0;

void escape(){
    int curX = x;
    int curY = y;
    do{
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(board[nx][ny] == '#'){ // 진행 방향에 벽이 있음
            int cnt = 0;
            while(board[nx][ny] != '.'){
                dir = (dir + 3) % 4; //반시계방향 회전
                nx = curX + dx[dir];
                ny = curY + dy[dir];
                cnt++;
                if(cnt > 4){ // 계속 회전만 한다면 강제 종료
                    ans = -1;
                    return;
                }    
            }

            // curX += dx[dir];
            // curY += dy[dir];
        }
        else if(board[nx][ny] == '.'){ // 벽이 없음
            curX = nx;
            curY = ny;
            if(board[nx + dx[(dir + 1) % 4]][ny + dy[(dir + 1) % 4]] != '#'){ // 가는 방향에 벽이 없을 경우
                dir = (dir + 1) % 4; // 시계방향 회전
            } 
            ++ans;
        }
        // cout << curX << " " << curY << '\n';
        // cout << ans << "\n\n";

        if(nx <= 0 || nx > N || ny <= 0 || ny > N){
            //cout << "escaped\n";
            ++ans;
            return;
        }
        
    }while(ans <= N * N);
    ans = -1;
    return;
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    cin >> x >> y;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    escape();

    cout << ans;

    return 0;
}