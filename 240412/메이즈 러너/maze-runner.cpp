#include <iostream>
#include <cmath>
#include <cstring>

#define MAX_N 11
#define MAX_M 10
#define DIR_NUM 4
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int board[MAX_N][MAX_N];
int temp[MAX_N][MAX_N]; // 회전할 때 쓸 배열
pair<int, int> pos[MAX_M]; // 참가자 위치 배열
pair<int, int> exits; // 출구

int sx, sy, siz; // 사각형 위치, 크기

int ans = 0;
int N, M, K;

bool notInRange(int x, int y){
    return x <= 0 || x > N || y <= 0 || y > N;
}

int calcDist(int x1, int x2, int y1, int y2){
    return abs(x1 - y1) + abs(y1 - y2);
}

void move() {
    // 거리 계산해서 옮기기
    for(int i = 1; i <= M; i++) {
        if(pos[i].first == exits.first && pos[i].second == exits.second)
            continue;
        
        if(pos[i].first != exits.first) {
            int nx = pos[i].first;
            int ny = pos[i].second;

            if(exits.first > nx) nx++;
            else nx--;

            if(!board[nx][ny]) {
                pos[i].first = nx;
                pos[i].second = ny;
                ans++;
                continue;
            }
        }

        if(pos[i].second != exits.second) {
            int nx = pos[i].first;
            int ny = pos[i].second;

            if(exits.second > ny) ny++;
            else ny--;

            if(!board[nx][ny]) {
                pos[i].first = nx;
                pos[i].second = ny;
                ans++;
                continue;
            }
        }
    }
}

void findSquare(){
     for(int s = 2; s <= N; s++) {
        for(int x1 = 1; x1 <= N - s + 1; x1++) {
            for(int y1 = 1; y1 <= N - s + 1; y1++) {
                int x2 = x1 + s - 1;
                int y2 = y1 + s - 1;

                if(!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2)) {
                    continue;
                }

                bool hasPlayer = false;
                for(int l = 1; l <= M; l++) {
                    if(x1 <= pos[l].first && pos[l].first <= x2 
                    && y1 <= pos[l].second && pos[l].second <= y2) {
                        if(!(pos[l].first == exits.first 
                        && pos[l].second == exits.second)) {
                            hasPlayer = true;
                        }
                    }
                }

                if(hasPlayer) {
                    sx = x1;
                    sy = y1;
                    siz = s;

                    return;
                }
            }
        }
    }
}

void rotate(){
    for(int x = sx; x < sx + siz; x++)
        for(int y = sy; y < sy + siz; y++) {
            if(board[x][y]) board[x][y]--;
        }

    for(int x = sx; x < sx + siz; x++)
        for(int y = sy; y < sy + siz; y++) {
            int ox = x - sx, oy = y - sy;
            int rx = oy, ry = siz - ox - 1;
            temp[rx + sx][ry + sy] = board[x][y];
        }

    for(int x = sx; x < sx + siz; x++)
        for(int y = sy; y < sy + siz; y++) {
            board[x][y] = temp[x][y];
        }

    for(int i = 1; i <= M; i++) {
        int x = pos[i].first;
        int y = pos[i].second;
        if(sx <= x && x < sx + siz && sy <= y && y < sy + siz) {
            int ox = x - sx, oy = y - sy;
            int rx = oy, ry = siz - ox - 1;
            pos[i] = make_pair(rx + sx, ry + sy);
        }
    }

    int x = exits.first;
    int y = exits.second;
    if(sx <= x && x < sx + siz && sy <= y && y < sy + siz) {
        int ox = x - sx, oy = y - sy;
        int rx = oy, ry = siz - ox - 1;
        exits = make_pair(rx + sx, ry + sy);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= M; i++){
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }

    int x, y;
    cin >> x >> y;
    exits = {x, y};
    
    for(int i = 1; i <= K; i++){
        move();
        bool is_all_escaped = true;
        for(int i = 1; i <= M; i++) {
            if(!(pos[i].first == exits.first && pos[i].second == exits.second)) {
                is_all_escaped = false;
            }
        }

        if(is_all_escaped) break;

        findSquare();
        rotate();
    }
    cout << ans << '\n';
    cout << exits.first << " " << exits.second;
    return 0;
}