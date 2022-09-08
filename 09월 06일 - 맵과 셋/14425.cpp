#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, cnt = 0;
    string word;
    cin >> n >> m;

    map<string, int> s; // 문자열 집합
    while(n--) { // 집합 s에 속한 문자열 입력
        cin >> word;
        s[word]++;
    }

    while(m--) { // 집합 s에 속한 문자열인가
        cin >> word;
        if(s[word]) cnt++;
    }

    cout << cnt;
    return 0;
}