#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>

#define MAX_N 20
#define MAX_M 30
using namespace std;

//플레이어(초기 능력치, 총, 점수, 뱡향)


vector<int> board[MAX_N + 1][MAX_N + 1]; // 총들의 정보
int playerBoard[MAX_N + 1][MAX_N + 1]; // 플레이어 위치(숫자로 표기)

int score[MAX_M + 1]; // 플레이어별 점수
tuple<int, int, int> playerPos[MAX_M + 1]; // x, y, dir
int info[MAX_M + 1]; // 플레이어별 초기 능력치
int gun[MAX_M + 1]; // 플레이어가 갖고 있는 총

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, k;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << playerBoard[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}


bool notInRange(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= n;
}

void getGun(int x, int y){
    int num = playerBoard[x][y];
    int gunAttack = gun[num];
    int maxGun = 0;
    int idx = 0;
    for(int i = 0; i < board[x][y].size(); i++){
        if(board[x][y][i] > maxGun){
            maxGun = board[x][y][i];
            idx = i;
        }
    }
    if(gunAttack < maxGun){
        gun[num] = maxGun;
        board[x][y][idx] = 0;
        board[x][y].push_back(gunAttack);
    }
}

void lose(int num, int x, int y){
    board[x][y].push_back(gun[num]); // 총 내려놓기
    gun[num] = 0;

    int dir = get<2>(playerPos[num]); // 방향 구하기
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while(!(playerBoard[nx][ny] == 0 && !notInRange(nx, ny))){
        dir = (dir + 1) % 4; // 오른쪽으로 회전
        nx = x + dx[dir];
        ny = y + dy[dir];
    }
    // cout <<"los1 : " << get<0>(playerPos[num]) <<" " << get<1>(playerPos[num]) << '\n';
    // cout << "lost : " << nx << " " << ny << '\n';
    playerBoard[nx][ny] = num;
    playerBoard[x][y] = 0;
    playerPos[num] = make_tuple(nx, ny, dir);
    if(board[nx][ny].size() > 0){
        getGun(nx, ny);
    }
}

bool fight(int num1, int num2, int x, int y){
    int attack1 = info[num1] + gun[num1];
    int attack2 = info[num2] + gun[num2];
    int attackGap = attack1 - attack2;
    
    int victory, defeat;
    if(attackGap > 0){
        victory = num1;
        defeat = num2;
    }
    else if(attackGap == 0){
        int info1 = info[num1], info2 = info[num2];
        if(info1 > info2){
            victory = num1;
            defeat = num2;
        }
        else{
            victory = num2;
            defeat = num1;
        }
    }
    else if(attackGap < 0){
        victory = num2;
        defeat = num1;
    }
    //cout << "fight : " << attackGap  << " lose : " << defeat << "win : " << victory<< '\n';

    // 진 플레이어 처리
    lose(defeat, x, y);

    if(victory == num1){
        score[num1] += abs(attackGap);
        playerBoard[x][y] = num1;
        return true; // 이김
    }
    score[num2] += abs(attackGap);
    playerBoard[x][y] = num2;
    return false; // 짐
}

void move(int num){
    int x, y, dir;
    tie(x, y, dir) = playerPos[num];

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(notInRange(nx, ny)){
        dir = (dir + 2) % 4; // 방향 전환
        nx = x + dx[dir];
        ny = y + dy[dir];
    }
    playerBoard[x][y] = 0;
    get<2>(playerPos[num]) = dir;
    if(playerBoard[nx][ny] != 0){ // 플레이어 있으면
        int isVictory = fight(num, playerBoard[nx][ny], nx, ny);
            if(isVictory){
                playerBoard[nx][ny] = num;

                playerPos[num] = make_tuple(nx, ny, dir); //위치 바꾸기
                getGun(nx, ny);

                if(board[nx][ny].size() != 0){ // 총이 있으면
                    getGun(nx, ny);
                }
            }    
    }
    else{
        playerPos[num] = make_tuple(nx, ny, dir);
        playerBoard[nx][ny] = num;
        if(board[nx][ny].size() != 0){ // 총이 있으면
            getGun(nx, ny);
        }
    }
    // for(int i = 1; i <= m; i++){
    //     cout << gun[i] << " ";
    // }
    // cout << '\n';
}


int main() {
    // 여기에 코드를 작성해주세요.
    //1. 번호 순서대로 플레이어 이동 (벽 만나면 방향 전환)
    //2. 다른 플레이어 있는지 확인
    //2-1. 없으면 총이 있는지 확인하고 장착하거나 교환
    //2-2. 있으면 싸우고 포인트 획득
    //2-2-1. 졌으면 원래 방향으로 이동
    //2-2-2. 근데 다른 플레이어 있거나 밖이면 빈칸 있을때까지 오른쪽 90도 회전
    //2-2-3. 공격력 높은 총 획득, 나머지 총은 바닥에

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int g;
            cin >> g;
            if(g != 0)
                board[i][j].push_back(g);
        }
    }

    for(int i = 1; i <= m; i++){
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        playerBoard[x - 1][y - 1] = i;
        playerPos[i] = make_tuple(x - 1, y - 1, d);
        info[i] = s;
    }

    for(int i = 0; i < k; i++){
        for(int num = 1; num <= m; num++)
            move(num);
        // for(int j = 1; j <= m; j++){
        //     cout << gun[j] << " ";
        // }
        // cout << '\n';
        // for(int j = 1; j <= m; j++){
        // cout << score[j] << " ";
        // }
        // cout << "\n\n";
        // print();
    }


    for(int i = 1; i <= m; i++){
        cout << score[i] << " ";
    }

    return 0;
}