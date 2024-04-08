#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int K;
int board[101][101];
int temp[101][101];
int ans = 0;

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

void gravity(){
    memset(temp, 0, sizeof(temp));

    for(int j = 0; j < N; j++){
        int nextRow = N - 1;
        for(int i = N - 1; i >= 0; i--){
            if(board[i][j] == 0)
                continue;
            temp[nextRow--][j] = board[i][j];
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = temp[i][j];
}

void explode(){
    bool isExploded;
    int curIdx;

    for(int j = 0; j < N; j++){
        do{    
            isExploded = false;
            curIdx = N - 1;
            while(curIdx >= 0){
                int endIdx = curIdx - 1; // 현재 바로 위에가 endIdx
                while(endIdx >= 0){
                    if(board[curIdx][j] == board[endIdx][j] && board[curIdx][j] != 0){
                        endIdx--; // 같으면 endIdx 더 위로
                    }
                    else{
                        break; // 아니면 종료
                    }
                }
                endIdx += 1; // -1 해놨던거 다시 밑으로 돌려놓기

                if(curIdx - endIdx + 1 >= M) { // 터지는 조건이 맞춰지면 없애버리기
                    for(int idx = curIdx; idx >= endIdx; idx--)
                        board[idx][j] = 0;
                    gravity();
                    isExploded = true;    
                }else{
                    curIdx--;
                }
            }
        } while(isExploded);
    }
}

void rotate(){
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            temp[i][j] = board[N - 1 - j][i];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = temp[i][j]; // 일단 그대로 회전
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    if(N == 1){
        if(M == 1){
            cout << 0;
        }
        else cout << 1;
        return 0;
    }

    for(int i = 0; i < K; i++){
        explode();
        rotate();
        gravity();
        explode();
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(board[i][j] != 0)
                ans++;
    }
    cout << ans;

    return 0;
}