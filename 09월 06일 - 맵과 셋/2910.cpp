#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

bool cmp(pair<int, pi> &p1, pair<int, pi> &p2) {
    // 1. 빈도 수 내림차순
    if(p1.second.first != p2.second.first) return p1.second.first > p2.second.first;
    // 2. 등장 순서 오름차순
    return p1.second.second < p2.second.second;
}

int main() {
    int n, c, num;
    cin >> n >> c;

    map<int, pi> m; // key: 숫자, value: (해당 숫자의 빈도 수, 등장 순서)
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(!m[num].first) m[num] = {1, i}; // 처음 등장한 숫자
        else m[num].first++; // 나중에 등장한 숫자
    }

    // map 내용을 vector로 옮겨서 정렬
    vector<pair<int, pi>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for(auto iter = v.begin(); iter != v.end(); iter++) {
        int freq = iter->second.first; // 해당 숫자 빈도 수
        for(int i = 0; i < freq; i++)
            cout << iter->first << ' ';
    }
    return 0;
}