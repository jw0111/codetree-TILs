#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dir = 0;
int x = 0, y = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        if(str[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        if(str[i] == 'F'){
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout << x << " " << y;
    return 0;
}