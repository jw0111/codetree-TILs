#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int board[5][5];
int temp[5][5];
map<char, int> dirMap;

void rotate(){
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[i][j] = board[4 - 1 - j][i]; // 시계방향 회전
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            board[i][j] = temp[i][j];
    }
}

void drop(){
    memset(temp, 0, sizeof(temp));
    
    for(int j = 0; j < 4; j++){
        int prevNum = -1, next_row = 3;
        for(int i = 3; i >= 0; i--){
            if(!board[i][j]) continue; // 비어있으면 넘어가기

            if(prevNum == -1){
                prevNum = board[i][j]; // 아직 떨어진 숫자가 없으면 prevNum 설정
            }
            else if(prevNum == board[i][j]){ // 이전 숫자가 지금 숫자랑 일치한다면 합치기
                temp[next_row--][j] = prevNum * 2; // 숫자 넣고 next_row 1 감소(위로)
                prevNum = -1;
            }
            else { // prevNum이 다르다면
                temp[next_row--][j] = prevNum;
                prevNum = board[i][j];
            }
        }
        if(prevNum != -1)
            temp[next_row--][j] = prevNum; // 혹시 prevNum이 -1이 아니라면 숫자 넣어주기
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = temp[i][j];
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    dirMap.insert({'D', 0});
    dirMap.insert({'R', 1});
    dirMap.insert({'U', 2});
    dirMap.insert({'L', 3});

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cin >> board[i][j];
    }

    char tempDir;
    cin >> tempDir;
    int dir = dirMap.at(tempDir);

    for(int i = 0; i < dir; i++)
        rotate();

    drop();

    for(int i = 0; i < 4 - dir; i++)
        rotate();
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }
    return 0;
}