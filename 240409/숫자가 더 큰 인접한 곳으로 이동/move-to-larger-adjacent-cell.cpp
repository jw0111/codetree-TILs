#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int board[101][101];
int r, c;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;
vector<int> ans;

void move(){
    int cur = board[r][c];
    q.push({r, c});
    ans.push_back(cur);
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        //cout <<"r, c :" << r<<" "<< c << '\n';
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            //cout << "board : " <<board[nx][ny] << '\n';
            if(cur < board[nx][ny]){
                q.push({nx, ny});
                ans.push_back(board[nx][ny]);
                cur = board[nx][ny];
                break;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    move();
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}