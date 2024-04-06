#include <iostream>
#include <cstring>
using namespace std;

int n;
int zenga[101];
int temp[101];
int s1, e1;
int s2, e2;
int cnt = 0;

void removeBlock(int s, int e){
    for(int i = s; i <= e; i++){
        zenga[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(zenga[i] != 0){
            ++cnt;
            temp[cnt] = zenga[i];
        }
    }
    memset(zenga, 0, sizeof(zenga));

    for(int i = 1; i <= cnt; i++)
        zenga[i] = temp[i];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> zenga[i];
        
    cin >> s1 >> e1;
    removeBlock(s1, e1);
    cnt = 0;
    memset(temp, 0, sizeof(temp));

    cin >> s2 >> e2;
    removeBlock(s2, e2);

    if(cnt == 0)
        cout << 0;
    else {
        cout << cnt << '\n';
        for(int i = 1; i <= cnt; i++)
            cout << temp[i] << '\n';
            
    }
    return 0;
}