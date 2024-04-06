#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> ans;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}