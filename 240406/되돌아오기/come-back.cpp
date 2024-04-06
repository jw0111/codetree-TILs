#include <iostream>
#include <map>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
map<char, int> dirMap;
int N;
int x = 0, y = 0;
int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    dirMap.insert({'N', 0});
    dirMap.insert({'S', 1});
    dirMap.insert({'W', 2});
    dirMap.insert({'E', 3});

    cin >> N;
    for(int i = 0; i < N; i++){
        char tmpDir;
        int dist;
        cin >> tmpDir >> dist;

        int dir = dirMap.at(tmpDir);
        for(int time = 0; time < dist; time++){
            x += dx[dir];
            y += dy[dir];
            ++ans;
            if(x == 0 && y == 0){
                cout << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}