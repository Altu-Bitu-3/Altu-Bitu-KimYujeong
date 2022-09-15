#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int median(int mid, map<int, int> m) { // 중앙값 구하기
    int idx = 0; // 인덱스 카운트
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(idx + iter->second >= mid) return iter->first; // 중앙값 발견
        idx += iter->second;
    }
}

int mode(map<int, int> m) { // 최빈값 구하기
    int ans, max = 0; // (각각 최빈값, 최빈값 빈도 저장)
    bool second = false;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        // 1. 최빈값 갱신
        if(iter->second > max) {
            ans = iter->first;
            max = iter->second;
            second = false;
        }
        // 2. 최빈값이 여러 개
        else if(iter->second == max && !second) {
            ans = iter->first;
            second = true;
        }
    }
    return ans;
}

int main() {
    int n, num, sum = 0;
    cin >> n;

    map<int, int> m; // (first : 정수, second : 등장 횟수)
    for(int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        m[num]++;
    }

    int mid = ((n % 2) ? n/2 + 1 : n/2); // 중앙값 인덱스
    int avg = round((double) sum / n);

    cout << (!avg ? 0 : avg) << '\n'; // 산술평균 (-0 방지)
    cout << median(mid, m) << '\n'; // 중앙값
    cout << mode(m) << '\n'; // 최빈값
    cout << (--m.end())->first - m.begin()->first; // 범위
    return 0;
}