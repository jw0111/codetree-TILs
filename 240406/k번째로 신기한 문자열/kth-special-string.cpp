#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    string T;
    vector<string> ans;
    cin >> n >> k >> T;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str.find(T) == 0)
            ans.push_back(str);
    }

    sort(ans.begin(), ans.end());
    cout << ans[k - 1];
    
    return 0;
}