#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    string date;
    string day;
    string weather;
    vector<tuple<string, string, string>> weatherCasts;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> date >> day >> weather;
        if(weather == "Rain"){
            weatherCasts.push_back(make_tuple(date, day, weather));
        }
    }
    sort(weatherCasts.begin(), weatherCasts.end());
    tuple<string, string, string> ans = weatherCasts[0];
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
    return 0;
}