#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, bool> m; // key : 직원 이름, value : 회사에 있는지 여부
    string name, log;
    while(n--) {
        cin >> name >> log;
        if(log == "enter") m[name] = true; // 출근 == 회사에 있음
        if(log == "leave") m[name] = false; // 퇴근 == 회사에 없음
    }

    // (map은 오름차순 정렬 -> 내림차순으로 출력하기 위해서는 end부터 탐색)
    for(auto iter = --m.end(); iter != --m.begin(); iter--) { // 회사에 있는 사람 출력
        if(m[iter->first]) cout << iter->first << '\n';
    }
    return 0;
}