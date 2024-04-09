#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[51][51];
int afterExplode[51][51];
int temp[51][51];
bool coupled[51][51];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};
int ans = 0;

void explode(int r, int c){
    int bomb = board[r][c];

    memset(afterExplode, 0, sizeof(afterExplode));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            afterExplode[i][j] = board[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < bomb; j++){
            int nx = r + dx[i] * j;
            int ny = c + dy[i] * j;

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            afterExplode[nx][ny] = 0;
        }
    }
}

void gravity(){
    memset(temp, 0, sizeof(temp));
    for(int j = 0; j < n; j++){
        int nextRow = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(afterExplode[i][j]){
                temp[nextRow--][j] = afterExplode[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            afterExplode[i][j] = temp[i][j];
        }
    }   
}

void findCouples(){
    int cnt = 0;
    memset(coupled, false, sizeof(coupled));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                
                if(afterExplode[i][j] == afterExplode[nx][ny] && !coupled[i][j]){ // 짝지어지지 않고 2개가 같다면
                    if(afterExplode[nx + dx[k]][ny + dy[k]] != afterExplode[i][j]){ // 3개 이상 겹치는 게 아니라면
                        coupled[i][j] = true;
                        coupled[nx][ny] = true;
                        ++cnt;
                        break;
                    }
                }
            }
        }
    }
   
    ans = max(ans, cnt);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            explode(i, j);
            gravity();
            findCouples();
        }
    }

    cout << ans;

    return 0;
}