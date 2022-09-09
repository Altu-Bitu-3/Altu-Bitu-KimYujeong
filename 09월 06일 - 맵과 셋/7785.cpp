#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s; // 회사에 있는 직원 저장하는 set
    string name, log;
    while(n--) {
        cin >> name >> log;
        if(log == "enter") s.insert(name); // 출근 == 회사에 있음
        if(log == "leave") s.erase(name); // 퇴근 == 회사에 없음
    }

    // (set은 오름차순 정렬 -> 내림차순으로 출력하기 위해서는 end부터 탐색)
    for(auto iter = s.rbegin(); iter != s.rend(); iter++) { // 회사에 있는 사람 출력
        cout << *iter << '\n';
    }
    return 0;
}