#include <iostream>
#include <cstring>
using namespace std;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int n, m;
int board[201][201];
int temp[201][201];

void explode(int c){
    int r = -1;
    for(int i = 0; i < n; i++){
        if(board[i][c]){
            r = i;
            break;
        }
    }
    if(r == -1)
        return;

    int bomb = board[r][c];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < bomb; j++){
            int nx = r + dx[i] * j;
            int ny = c + dy[i] * j;

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            board[nx][ny] = 0;
        }
    }
}

void gravity(){
    memset(temp, 0, sizeof(temp));

    for(int j = 0; j < n; j++){
        int nextRow = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(board[i][j] == 0)
                continue;
            temp[nextRow--][j] = board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            board[i][j] = temp[i][j];
    }
} 

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    for(int bomb = 0; bomb < m; bomb++){
        int c;
        cin >> c;
        explode(c - 1);    
        gravity();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }
    return 0;
}