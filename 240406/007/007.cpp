#include <iostream>
#include <string>
using namespace std;

class Mission {
    private:
        string secretCode;
        char point;
        int time;
    public:
        Mission(string secretCode, int point, int time)
        :secretCode(secretCode), point(point), time(time)
        {}

        void print(){
            cout << "secret code : " << secretCode << '\n';
            cout << "meeting point : " << point << '\n';
            cout << "time : " << time;
        }
};

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    char p;
    int t;
    cin >> s >> p >> t;
    
    Mission mission(s, p, t);
    mission.print();

    return 0;
}