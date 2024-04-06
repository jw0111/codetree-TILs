#include <iostream>
#include <cstring>
using namespace std;

int bomb[101];
int temp[101];

int N, M;
int cnt = 1;
int idx = 0;
bool isExploded = true;

void print(){
    for(int i = 0; i < N; i++)
        cout << bomb[i] << " ";
    cout << '\n';
}

bool explode(){
    isExploded = false;
    for(int i = 0; i < N; i++){
        if(bomb[i] == bomb[i + 1]){
            ++cnt;
            //cout << "cnt : " << cnt << '\n';
        }
        else{
            if(cnt >= M){
                for(int j = 0; j < cnt; j++){
                    bomb[i - j] = 0;
                }
                isExploded = true;
            }
            cnt = 1;
        }
    }
    return isExploded;
}

void gravity(){
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < N; i++){
        if(bomb[i] != 0){
            temp[idx] = bomb[i];
            ++idx;
        }
    }

    memset(bomb, 0, sizeof(bomb));
    for(int i = 0; i <= cnt; i++){
        bomb[i] = temp[i];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> bomb[i];

    while(true){
        if(!isExploded)
            break;
        cnt = 1;
        explode();

        idx = 0;
        gravity();
    }
    cout << idx << '\n';
    for(int i = 0; i < idx; i++){
        cout << bomb[i] << '\n';
    }

    return 0;
}