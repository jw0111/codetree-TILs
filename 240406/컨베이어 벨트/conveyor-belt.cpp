#include <iostream>
using namespace std;

int conv1[201];
int conv2[201];
int n, t;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> conv1[i];
    }
    for(int i = n - 1; i >= 0; i--){
        cin >> conv2[i];
    }
    for(int i = 0; i < t; i++){
        int tmp1, tmp2;
        tmp1 = conv1[n - 1];
        tmp2 = conv2[0];
        for(int j = n - 1; j > 0; j--)
            conv1[j] = conv1[j - 1];
        for(int j = 0; j < n; j++)
            conv2[j] = conv2[j + 1];
        conv1[0] = tmp2;
        conv2[n - 1] = tmp1;
    }

    for(int i = 0; i < n; i++)
        cout << conv1[i] << " ";
    cout << '\n';
    for(int i = n - 1; i >= 0; i--)
        cout << conv2[i] << " ";

    return 0;
}