#include <iostream>
#include <vector>

using namespace std;

int slidingWindow(int n, int m, int k, vector<int> money) {
    int cnt = 0, sum = 0;
    for(int i = 0; i < m; i++) {
        sum += money[i];
    }
    if(sum < k) { // 방범 장치에 들키지 않고 훔칠 수 있는 경우
        cnt++;
    }
    if(n == m) {
        return cnt;
    }

    for(int i = 1; i < n; i++) { // 슬라이딩 윈도우
        sum -= money[i-1]; // 왼쪽 집 훔치기 취소
        sum += money[(i-1+m) % n]; // 오른쪽 집 훔치기
        if(sum < k) { // 방범 장치에 들키지 않고 훔칠 수 있는 경우
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int t, n, m, k;
    cin >> t;

    while(t--) { // 테스트 케이스
        cin >> n >> m >> k;

        vector<int> money(n, 0);
        for(int i = 0; i < n; i++) { // 돈의 양 입력
            cin >> money[i];
        }
        cout << slidingWindow(n, m, k, money) << '\n';
    }
    return 0;
}