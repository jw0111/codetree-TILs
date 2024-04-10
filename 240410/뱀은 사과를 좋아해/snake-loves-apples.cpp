#include <iostream>
#include <map>
#include <queue>
using namespace std;

int N, M, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dir;
map<char, int> dirMap;
queue<pair<int, int>> snake;
int ans = 0;

int board[101][101]; // 사과 2, 뱀 1

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

bool move(int p){
    for(int i = 0; i < p; i++){
        int x = snake.back().first;
        int y = snake.back().second;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //cout << nx << " " << ny << '\n';
        if(nx <= 0 || nx > N || ny <= 0 || ny > N || board[nx][ny] == 1){
            if(nx != snake.front().first || ny != snake.front().second){
                ++ans;
                return false; // 뱀이 격자 밖으로 나가거나 꼬였을 경우 종료
            }
        }
        int cur = board[nx][ny]; //현재 셀
        snake.push({nx, ny});
        board[nx][ny] = 1;
        
        if(cur != 2){ // 사과가 없을 경우
            int tailX = snake.front().first;
            int tailY = snake.front().second;
            board[tailX][tailY] = 0;
            snake.pop();
        } 
        ++ans;
    }
    //print();
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    dirMap.insert({'U', 0});
    dirMap.insert({'D', 1});
    dirMap.insert({'R', 2});
    dirMap.insert({'L', 3});

    snake.push({1, 1});
    board[1][1] = 1;

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    for(int i = 0; i < K; i++){
        char d;
        int p;
        cin >> d >> p;
        dir = dirMap.at(d);
        bool canMove = move(p);
        if(!canMove) break;
    }

    cout << ans;

    return 0;
}