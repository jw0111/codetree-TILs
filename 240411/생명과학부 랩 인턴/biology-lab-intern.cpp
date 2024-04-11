#include <iostream>
#include <cstring>
#include <tuple>
#include <map>
#include <algorithm>

#define MAX_NM 101
#define DIR_NUM 4

using namespace std;

int n, m, k;
int dx[4] = {0, 1, -1, 0}; // 3 - dir -> 방향전환
int dy[4] = {-1, 0, 0, 1};
map<int, int> dirMap;

vector<tuple<int, int, int, bool>> molds[MAX_NM][MAX_NM]; // 크기 방향 속도 확인여부
vector<tuple<int, int, int, bool>> temp[MAX_NM][MAX_NM];

int ans = 0;

tuple<int, int, int> nextPos(int x, int y, int speed, int dir){
    for(int t = 0; t < speed; t++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx <= 0 || nx > n || ny <= 0 || ny > m){
            dir = 3 - dir; // 방향 전환
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    //cout << "nextPos : " << x << " " << y << " " << dir << '\n';
    return make_tuple(x, y, dir);
}

void moveAll(){
    for(int i = 1; i <= n; i++){ // temp 초기화
        for(int j = 1; j <= m; j++){
            temp[i][j].clear();
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int a = 0; a < molds[i][j].size(); a++){
                int size, dir, speed;
                bool checked;
                tie(size, dir, speed, checked) = molds[i][j][a];
                if(!checked){
                    tuple<int, int, int> next = nextPos(i, j, speed, dir);
                    int nx, ny, ndir;
                    tie(nx, ny, ndir) = next;
                    temp[nx][ny].push_back(make_tuple(size, ndir, speed, checked));
                }
            }
        }
    }
}

void eat(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(temp[i][j].size() > 1){
                sort(temp[i][j].begin(), temp[i][j].end());
                while(temp[i][j].size() != 1){
                    temp[i][j].pop_back();
                }
            }
        }
    }


    for(int i = 1; i <= n; i++){ // molds 초기화
        for(int j = 1; j <= m; j++){
            molds[i][j].clear();
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            molds[i][j] = temp[i][j];
        }
    }

}

void watch(){
    for(int t = 1; t <= m; t++){
        for(int i = 1; i <= n; i++){
            if(molds[i][t].size() > 0){ // 곰팡이 발견
                int size, dir, speed;
                bool checked;
                tie(size, dir, speed, checked) = molds[i][t][0];
                ans += (-size);
                //cout << "info and size: " << t << " " << i << " " << size << '\n'; 
                get<3>(molds[i][t][0]) = true;
                break;
            }
        }
        moveAll();
        eat();
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    dirMap.insert({1, 2});
    dirMap.insert({2, 1});
    dirMap.insert({3, 3});
    dirMap.insert({4, 0});

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x, y, s, d, b;
        cin >> x >> y >> s >> d >> b;
        d = dirMap.at(d); // 방향 배열에 맞게 변환
        molds[x][y].push_back(make_tuple(-b, d, s, false)); // 크기 순서대로니까 음수 변환
    }
    watch();
    cout << ans;
    return 0;
}