#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[51][51];
int afterExplode[51][51];
int temp[51][51];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 1; k <= 2; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                
                if(afterExplode[i][j] == afterExplode[nx][ny] && afterExplode[i][j] != 0){ // 2개가 같다면
                    //cout << i << ", " << j << " and " << nx << ", " << ny <<'\n';
                    ++cnt;
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << afterExplode[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << coupled[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    ans = max(ans, cnt);
    //     cout << ans;
    // cout << '\n';
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