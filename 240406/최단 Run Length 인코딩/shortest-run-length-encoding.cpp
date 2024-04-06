#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string A;
    cin >> A;
    int ans = 987654321;
    
    for(int i = 0; i < A.length(); i++){
        string result;
        int cnt = 1;
        for(int j = 0; j < A.length(); j++){
            if(A[j] == A[j + 1]){
                ++cnt; 
            } else {
                result += A[j];
                result += to_string(cnt);
                cnt = 1;
            }
        }
        int len = result.length();
        ans = min(ans, len);
        rotate(A.begin(), A.begin() + 1, A.end());
    }
    cout << ans;

    return 0;
}