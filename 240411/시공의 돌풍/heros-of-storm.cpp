#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX_NM 51
#define DIR_NUM 4

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0}; //반시계 방향(오 위 왼 아)

int board[MAX_NM][MAX_NM];
int temp[MAX_NM][MAX_NM];

vector<pair<int, int>> cleaner; // 공기청정기 위치 저장

int n, m, t;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}


void diffuse(){
    memset(temp, 0, sizeof(temp)); // temp배열 초기화

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != -1){ // 공기청정기 위치가 아니라면 확산 시작
                int dust = floor(board[i][j] / 5);
                int nx, ny;
                for(int dir = 0; dir < DIR_NUM; dir++){
                    nx = i + dx[dir];
                    ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == -1) // 격자 벗어나거나 공기청정기 위치
                        continue;
                    temp[nx][ny] += dust; // temp 배열에 더해질 먼지 값 저장
                    board[i][j] -= dust; // 확산한 만큼 먼지 빼기
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] += temp[i][j]; // 현재 먼지에 확산된 만큼 더하기
        }
    }
}

void circulate(){
    // 1. 위쪽 방향 순환
    int r, c;
    r = cleaner[0].first, c = cleaner[0].second; // 공기청정기 위치
    int curDust = board[r][++c]; // 없어지는 숫자 저장
    int dir = 0;
    int nx, ny;
    do{
        nx = r + dx[dir];
        ny = c + dy[dir];
        if(board[nx][ny] == -1)
            break;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            dir = (dir + 1) % 4; // 방향 회전
            nx = r + dx[dir];
            ny = c + dy[dir];
        } 
        //cout << nx << " "<< ny << " " << board[nx][ny] << '\n';
        int tmp = board[nx][ny];
        board[nx][ny] = curDust;
        curDust = tmp;
        r = nx;
        c = ny;
        //cout << r << " " << c << '\n';
    }while(cleaner[0].first != r || cleaner[0].second != c);
    r = cleaner[0].first, c = cleaner[0].second;
    board[r][++c] = 0; // 공기청정기에서 나온 칸은 0으로


    // 2. 아래쪽 방향 순환
    r = cleaner[1].first, c = cleaner[1].second; // 공기청정기 위치
    curDust = board[r][++c]; // 없어지는 숫자 저장
    dir = 0;
    do{
        nx = r + dx[dir];
        ny = c + dy[dir];
        if(board[nx][ny] == -1)
            break;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            dir = (dir + 3) % 4; // 방향 회전
            nx = r + dx[dir];
            ny = c + dy[dir];
        } 
        //cout << nx << " "<< ny << " " << board[nx][ny] << '\n';
        int tmp = board[nx][ny];
        board[nx][ny] = curDust;
        curDust = tmp;
        r = nx;
        c = ny;
        //cout << r << " " << c << '\n';
    }while(cleaner[1].first != r || cleaner[1].second != c);
    r = cleaner[1].first, c = cleaner[1].second;
    board[r][++c] = 0; // 공기청정기에서 나온 칸은 0으로
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                cleaner.push_back({i, j});
            }
        }
    }

    while(t--){
        diffuse();
        circulate();
        //print();
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != -1){
                ans += board[i][j];
            }
        }
    }
    cout << ans;

    return 0;
}