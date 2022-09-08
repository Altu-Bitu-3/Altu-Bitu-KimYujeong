#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int cntPass(int n, vector<pi> candidate) {
    int cnt = 1; // (서류 1위 지원자 포함)

    int limit = candidate[0].second; // (limit보다 면접 순위가 좋아야 합격)
    for(int i = 1; i < n; i++) {
        // i번째 지원자는 0 ~ i-1번째까지의 지원자보다 면접 순위가 좋아야 함
        if(candidate[i].second < limit) { // 합격자 발견
            cnt++;
            limit = candidate[i].second;
        }
    }
    return cnt;
}

int main() {
    int t, n;
    cin >> t;

    while(t--) { // 테스트 케이스 입력
        cin >> n;

        vector<pi> candidate (n, {0, 0});
        for(int i = 0; i < n; i++) // 지원자 성적 입력
            cin >> candidate[i].first >> candidate[i].second;

        sort(candidate.begin(), candidate.end()); // 서류 순위 오름차순
        cout << cntPass(n, candidate) << '\n';
    }
    return 0;
}