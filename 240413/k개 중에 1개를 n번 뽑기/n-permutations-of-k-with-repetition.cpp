#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<int> num;
int result[10];

void perm(int cnt){
    if(cnt == N){
        for(int i = 0; i < N; i++){
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < K; i++){
        result[cnt] = num[i];
        perm(cnt + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> K >> N;
    for(int i = 1; i <= K; i++){
        num.push_back(i);
    }

    perm(0);

    return 0;
}