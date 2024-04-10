#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N 21
#define NO_EXISTS make_pair(-1, -1)
#define DIR_NUM 4
#define MAX_M 201

using namespace std;

int n, m, c;
int board[MAX_N][MAX_N]; // 전체 보드
bool visit[MAX_N][MAX_N]; // 방문 여부
int dist[MAX_N][MAX_N]; // 전체 거리 저장
bool isMoved[MAX_M]; // 승객 태웠는 지 저장

vector<tuple<int, int, int, int>> passengers; // 시작 위치, 끝 위치
queue<pair<int, int>> q;
pair<int, int> bestPos = NO_EXISTS; // 태울 승객 위치
pair<int, int> curPos; // 현재 자동차 위치

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(pair<int, int> startPos){
    memset(visit, false, sizeof(visit));

    int startX, startY;
    tie(startX, startY) = startPos;

    visit[startX][startY] = true;
    dist[startX][startY] = 0;
    q.push({startX, startY});

    while(!q.empty()){
        int curX, curY;
        tie(curX, curY) = q.front();
        q.pop();

        for(int i = 0; i < DIR_NUM; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            if(board[nx][ny] == 0 && !visit[nx][ny]){
                q.push({nx, ny});
                visit[nx][ny] = 1;
                dist[nx][ny] = dist[curX][curY] + 1;
            }
        }
    }
}

bool needUpdateBest(pair<int, int> a){
    if(bestPos == NO_EXISTS){
        return true;
    }

    int bestX, bestY;
    tie(bestX, bestY) = bestPos;

    int curX, curY;
    tie(curX, curY) = a;

    return make_tuple(dist[curX][curY], curX, curY) 
    < make_tuple(dist[bestX][bestY], bestX, bestY);
}

bool movePassenger(){
    bfs(curPos); // 모든 거리 구하기

    int bestIdx = -1;
    bestPos = NO_EXISTS;
    for(int i = 0; i < passengers.size(); i++){
        int sx, sy, ex, ey;
        tie(sx, sy, ex, ey) = passengers[i];
        if(isMoved[i] || c < dist[sx][sy] || !visit[sx][sy]) // 이미 태웠거나, 도달 불가능하거나, 연료 부족한 경우
            continue;
        if(needUpdateBest({sx, sy})){
            bestPos = {sx, sy};
            bestIdx = i;
        }
    }

    if(bestPos == NO_EXISTS){ // 태울 수 있는 승객 없으면 불가
        return false;
    }

    int sx, sy, ex, ey;
    tie(sx, sy, ex, ey) = passengers[bestIdx];

    curPos = {sx, sy};
    c -= dist[sx][sy]; // 차 이동

    bfs(curPos); // 다시 최단 거리 계산

    if(!visit[ex][ey] || c < dist[ex][ey]) // 이동할 수 없으면 불가
        return false;
    
    curPos = {ex, ey};
    c -= dist[ex][ey]; // 차 이동

    isMoved[bestIdx] = true; // 승객 이동 완료
    c += (dist[ex][ey] * 2); // 차 충전

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    curPos = {x, y};

    for(int i = 0; i < m; i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        passengers.push_back(make_tuple(sx, sy, ex, ey));
    }

    for(int i = 0; i < m; i++){
        if(!movePassenger()){
            cout << -1;
            return 0;
        }
    }

    cout << c;
    return 0;
}