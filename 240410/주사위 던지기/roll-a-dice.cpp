#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;
int r, c;
int board[101][101];
int dir = 0; // L: 0, R: 1, U: 2, D: 3
map<char, int> dirMap;
int up, fr, ri; // 위, 앞, 오른쪽 숫자
int ans = 0;

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void roll(){
    int nx = r + dx[dir];
    int ny = c + dy[dir];
    if(nx <= 0 || nx > n || ny <= 0 || ny > n)
        return;

    if(dir == 0){
        swap(up, ri);
        ri = 7 - ri;
    }
    else if(dir == 1){
        swap(up, ri);
        up = 7 - up;
    }
    else if(dir == 2){
        swap(up, fr);
        fr = 7 - fr;
    }
    else if(dir == 3){
        swap(up, fr);
        up = 7 - up;
    }

    board[nx][ny] = 7 - up;
    r = nx;
    c = ny;
}


int main() {
    // 여기에 코드를 작성해주세요.
    dirMap.insert({'L', 0});
    dirMap.insert({'R', 1});
    dirMap.insert({'U', 2});
    dirMap.insert({'D', 3});

    cin >> n >> m >> r >> c;
    up = 1, fr = 2, ri = 3;
    board[r][c] = 6;

    for(int i = 0; i < m; i++){
        char cmd;
        cin >> cmd;
        dir = dirMap.at(cmd);
        //cout<< dir << '\n';
        roll();
        //print();
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j])
                ans += board[i][j];
        }
    }
    cout << ans;
    return 0;
}