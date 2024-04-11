#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 51
#define DIR_NUM 4
#define NO_EXISTS make_pair(-1, -1)

using namespace std;

vector<tuple<int, int, int>> board[MAX_N][MAX_N]; // 번호, 점수, 기절시간, 이동 여부 (탈락하면 0,0으로 이동)

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 위쪽부터 시계 방향
int N, M, P, C, D;
int Rr, Rc; // 루돌프 위치
pair<int, int> bestSantaPos; // 우선순위 높은 산타 위치
int bestDist;

int calcDist(int srx, int sry, int destx, int desty){ // 거리 계산 함수
    return pow(srx - destx, 2) + pow(sry - desty, 2);
}

bool notInRange(int x, int y){
    return x <= 0 || x > N || y <= 0 || y > N;
}

void outOfBoard(int x, int y){
    board[0][0].push_back(board[x][y][0]); // 0 0으로 이동
    //cout << "out : " << get<0>(board[x][y][0]) <<" " << get<1>(board[x][y][0]) <<" " << get<2>(board[x][y][0]) << '\n';
    board[x][y].clear();
    --P; //산타 수 감소
}

void interaction(int x, int y, int dir){ // 산타끼리 상호작용
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(notInRange(nx, ny)){ // 밖으로 나가면 탈락
        outOfBoard(x, y);
        return;
    }
    if(board[nx][ny].size() > 0)
        interaction(nx, ny, dir);
    board[nx][ny] = board[x][y];
    return;
}

void Crash(pair<int, int> pos, bool isSanta, int dir){ // 산타가 충돌한거면 true, 아니면 false
    int nx, ny;
    if(isSanta){
        dir = (dir + 4) % 8; // 방향 반대로 변경
        get<1>(board[pos.first][pos.second][0]) += D;
        get<2>(board[pos.first][pos.second][0]) = 1;
        nx = pos.first + dx[dir] * D;
        ny = pos.second + dy[dir] * D;
    }
    else{
        get<1>(board[pos.first][pos.second][0]) += C;
        get<2>(board[pos.first][pos.second][0]) = 2;
        nx = pos.first + dx[dir] * C;
        ny = pos.second + dy[dir] * C;
    }

    if(notInRange(nx, ny)){ // 탈락이면
        outOfBoard(pos.first, pos.second);
        if(!isSanta)
            bestSantaPos = NO_EXISTS;
        return;
    }
    if(board[nx][ny].size() > 0){ // 튕겨나간 자리에 산타가 있으면
        interaction(nx, ny, dir); // 산타 옮겨주고
    }
    board[nx][ny] = board[pos.first][pos.second];
    //cout << "test test. : " << nx << " " << ny << " " << board[pos.first][pos.second].size() << '\n';
    board[pos.first][pos.second].clear(); // 옮겨주고 원래 자리 초기화

    //cout << "crashed : " <<pos.first << " " <<pos.second << " , "<< nx << " " << ny << '\n';
}

bool needUpdateSanta(int dist, int r, int c){ // bestSantaPos 바꿔야하는지
    if(bestSantaPos == NO_EXISTS){
        return true;
    }
    
    return make_tuple(dist, -r, -c) < make_tuple(bestDist, -bestSantaPos.first, -bestSantaPos.second);
}

void findBestSanta(){
    bestSantaPos = NO_EXISTS;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j].size() > 0){
                int curDist = calcDist(i, j, Rr, Rc);
                if(needUpdateSanta(curDist, i, j)){
                    bestSantaPos = {i , j};
                    bestDist = curDist;
                }
            }
        }
    }
    //cout << "bestSantaPos : " << bestSantaPos.first << " " << bestSantaPos.second << '\n';
}

void moveCow(){ // 루돌프 돌진
    int dir = -1;
    int di = 987654321;
    int nx, ny;
    for(int i = 0; i < 8; i++){
        nx = Rr + dx[i];
        ny = Rc + dy[i];
        if(notInRange(nx, ny))
            continue;
        int curDist = calcDist(nx, ny, bestSantaPos.first, bestSantaPos.second);
        if(curDist < di){
            di = curDist;
            dir = i; // 움직일 방향 결정
        }
    }
 
    nx = Rr + dx[dir]; 
    ny = Rc + dy[dir]; 
    if(board[nx][ny].size() > 0){
        // 충돌 처리
        Crash(bestSantaPos, false, dir);
    }
    Rr = nx; // 루돌프 이동
    Rc = ny;
    //cout << "Rr Rc : " << Rr << " " << Rc << '\n';
}

void moveSanta(){ // 산타 돌진
    vector<tuple<int, int, int>> santas; // 번호, x, y
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j].size() > 0){ // 산타 번호별로 위치 저장해두기
                int num = get<0>(board[i][j][0]);
                santas.push_back(make_tuple(num, i, j));
            }      
        }
    }
    
    sort(santas.begin(), santas.end());
    for(int idx = 0; idx < santas.size(); idx++){
        int i = get<1>(santas[idx]);
        int j = get<2>(santas[idx]);
        if(get<2>(board[i][j][0]) > 0){ // 산타가 기절해있으면
            get<2>(board[i][j][0])--; // 기절 턴 하나 줄여주기
            continue;
        }
        int nx, ny;
        int bestDist = calcDist(i, j, Rr, Rc), dir = -1;
        for(int d = 0; d < 8; d += 2){ // 상우하좌 이동
            nx = i + dx[d];
            ny = j + dy[d];
            if(notInRange(nx, ny) || board[nx][ny].size() > 0) // 벗어나거나 누구 있으면
                continue;
            int curDist = calcDist(nx, ny, Rr, Rc);
            if(curDist < bestDist){
                dir = d;
                bestDist = curDist;
            }
        }
        if(dir >= 0){ // 갈 방향이 있으면
            nx = i + dx[dir];
            ny = j + dy[dir];
            board[nx][ny] = board[i][j];
            board[i][j].clear();

            if(nx == Rr && ny == Rc){ // 루돌프랑 충돌
                Crash({nx, ny}, true, dir);
            }
        }
        else{
            nx = i, ny = j;
        }
        // cout << "santa : " << get<0>(board[nx][ny][0]) << " " << get<1>(board[nx][ny][0]) << " " <<
        // get<2>(board[nx][ny][0]) <<"nx, ny : " << nx << " " <<ny << '\n';
   }
}


void addScore(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j].size() > 0){ // 보드에 남아있는 산타가 있다면
                get<1>(board[i][j][0]) += 1;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> P >> C >> D;
    cin >> Rr >> Rc;
    for(int i = 0; i < P; i++){
        int num, tmpx, tmpy;
        cin >> num >> tmpx >> tmpy;
        board[tmpx][tmpy].push_back(make_tuple(num, 0, 0));
    }

    while(M--){
        findBestSanta();
        //cout << "findsanta\n";
        moveCow();
        //cout << "moveCow\n";
        moveSanta();
        // cout << "moveSanta\n";
        addScore();
        //cout << "addScore\n";
        if(P == 0)
            break;
        //cout << "===========\n";
    }

    vector<tuple<int, int, int>> ans;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int a = 0; a < board[i][j].size(); a++){
                //cout << "ans : " << get<0>(board[i][j][a]) <<" " << get<1>(board[i][j][a]) <<" " << get<2>(board[i][j][a]) << '\n';
                ans.push_back(board[i][j][a]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << get<1>(ans[i]) << " ";
    }
    return 0;
}