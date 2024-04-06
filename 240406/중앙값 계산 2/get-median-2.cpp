#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        ans.push_back(num);
        sort(ans.begin(), ans.end());
        if(i % 2 != 0){
            cout << ans[i / 2] << " ";
        }
    }
    return 0;
}