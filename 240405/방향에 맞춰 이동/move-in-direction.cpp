#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;

int convert(char dir){
    if(dir == 'N')
        return 0;
    if(dir == 'S')
        return 1;
    if(dir == 'W')
        return 2;
    if(dir == 'E')
        return 3;
}

int main() {
    int x = 0, y = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        char dir;
        int dist;
        cin >> dir >> dist;

        int convertDir = convert(dir);
        x += dx[convertDir]*dist;
        y += dy[convertDir]*dist;
        //cout << x << " " << y << '\n';
    }    
    cout << y << " " << x;
    return 0;
}