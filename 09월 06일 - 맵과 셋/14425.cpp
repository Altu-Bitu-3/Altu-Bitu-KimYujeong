#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, cnt = 0;
    string word;
    cin >> n >> m;

    set<string> s; // 문자열 집합
    while(n--) { // 집합 s에 속한 문자열 입력
        cin >> word;
        s.insert(word);
    }

    while(m--) { // 집합 s에 속한 문자열인가
        cin >> word;
        if(s.find(word) != s.end()) cnt++;
    }

    cout << cnt;
    return 0;
}