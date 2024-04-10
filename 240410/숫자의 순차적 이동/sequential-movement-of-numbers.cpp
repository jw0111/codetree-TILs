#include <iostream>
using namespace std;

int n, m;
int board[21][21];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int r, c;
int dir = 0;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}


void swap(int x1, int y1, int x2, int y2){
    int temp = board[x1][y1];
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
}

void findIdx(int num){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == num){
                r = i;
                c = j;
                return;
            }
        }
    }
}

void move(){
    int nx, ny;
    dir = 0;
    for(int i = 0; i < 8; i++){
        nx = r + dx[i];
        ny = c + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(board[nx][ny] > board[r + dx[dir]][c + dy[dir]]){
            dir = i;
        }
    }
    nx = r + dx[dir];
    ny = c + dy[dir];
    swap(r, c, nx, ny);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    while(m--){
        for(int i = 1; i <= n * n; i++){
            findIdx(i);
            move();
        }
    }
    print();

    return 0;
}