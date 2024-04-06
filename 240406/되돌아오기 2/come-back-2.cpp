#include <iostream>
#include <string>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int x = 0, y = 0;
int dir = 0;
int ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    string cmd;
    cin >> cmd;
    for(int i = 0; i < cmd.length(); i++){
        ++ans;
        if(cmd[i] == 'L')
            dir = (dir + 3) % 4;
        else if(cmd[i] == 'R')
            dir = (dir + 1) % 4;
        else if(cmd[i] == 'F'){
            x += dx[dir];
            y += dy[dir];
            if(x == 0 && y == 0){
                cout << ans;
                break;
            }
            //cout << x << " " << y << '\n';
        }
    }
    if(x != 0 || y != 0)
        cout << -1;
    
    return 0;
}