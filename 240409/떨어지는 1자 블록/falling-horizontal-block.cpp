#include <iostream>
using namespace std;

int n, m, k;
int board[101][101];
int rowIdx = 1;

void dropBlock(){
    for(int i = 1; i <= n; i++){
        for(int j = k; j <= m; j++){
            if(board[i][j]){
                rowIdx = i - 1;
                return;
            }
        }
    }
    rowIdx = n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    dropBlock();

    for(int j = k; j < k + m; j++){
        board[rowIdx][j] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}