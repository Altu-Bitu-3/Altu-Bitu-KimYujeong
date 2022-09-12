#include <iostream>
#include <map>

using namespace std;

int cntUniqueStyle(map<string, int> m) { // 서로 다른 의상 조합 개수 세기
    int cnt = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        // (iter->second == 의상 개수)
        // 의상 개수 + 안 입는 경우
        cnt *= (iter->second + 1);
    }
    return cnt - 1; // (-1 : 알몸 상태 제외)
}

int main() {
    int t, n;
    cin >> t;

    while(t--) { // 테스트케이스
        cin >> n; // 의상 수

        map<string, int> m; // key: 의상 종류, value: 해당 종류의 의상 개수
        string clothes, type;
        while(n--) { // 혜빈이가 가진 의상 입력
            cin >> clothes >> type;
            m[type]++;
        }
        cout << cntUniqueStyle(m) << '\n';
    }
    return 0;
}