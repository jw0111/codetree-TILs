#include <iostream>
using namespace std;

int board[21][21];
int n, m;

bool checksquare(int i, int j, int l, int k){
    for(int a = i; a <= l; a++){
        for(int b = j; b <= k; b++){
            if(board[a][b] <= 0)
                return false;
        }
    }
    return true;
}

int main() {
    int ans = 0;
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                    if(checksquare(i, j, k, l)){
                        int cnt = (k + 1 - i) * (l + 1 - j);
                        //cout << i << " " << j << " " << k << " " << l << " " << cnt <<'\n';
                        ans = max(ans, cnt);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}