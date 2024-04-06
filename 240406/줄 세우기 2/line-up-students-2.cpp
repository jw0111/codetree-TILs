#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> info;
vector<info> students;

bool compare(info a, info b){
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int N;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;
    for(int i = 0; i < N; i++){
        int h, w;
        cin >> h >> w;
        students.push_back(make_tuple(h, w, i + 1));
    }
    sort(students.begin(), students.end(), compare);
    for(int i = 0; i < N; i++){
        cout << get<0>(students[i]) << " " << get<1>(students[i]) << " " << get<2>(students[i]) << '\n';
    }
    return 0;
}