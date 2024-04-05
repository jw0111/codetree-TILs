#include <iostream>
#include <map>
using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int n, t;
int r, c;
map<char, int> dirMap;

int main() {
    dirMap.insert({'U', 0});
    dirMap.insert({'L', 1});
    dirMap.insert({'R', 2});
    dirMap.insert({'D', 3});

    char tmpDir;
    cin >> n >> t;
    cin >> c >> r >> tmpDir;

    int dir = dirMap.at(tmpDir);

    for(int i = 0; i < t; i++){
        int nr = r + dx[dir];
        int nc = c + dy[dir];

        if(nr <= 0 || nr > n || nc <= 0 || nc > n){
            dir = 3 - dir;
            continue;
        }

        r += dx[dir];
        c += dy[dir];
        //cout << r << " " << c << '\n';
    }

    cout << c << " " << r;

    return 0;
}