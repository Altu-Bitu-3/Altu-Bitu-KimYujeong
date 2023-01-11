#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTime(int n, vector<int> p) {
    vector<int> dp (n+1, 0); // dp[i] : i번째 사람이 돈을 인출하는데 필요한 시간
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + p[i]; // (i번째 사람이 기다리는 시간 + i번째 사람이 인출하는데 걸리는 시간)
    }

    int time = 0; // 각 사람이 돈을 인출하는데 필요한 시간의 합
    for(int i = 1; i <= n; i++) {
        time += dp[i];
    }
    return time;
}

int main() {
    int n;
    cin >> n;

    vector<int> p (n+1, 0);
    for(int i = 1; i <= n; i++) // 돈을 인출하는데 필요한 시간 입력
        cin >> p[i];
    sort(p.begin(), p.end()); // 오름차순 정렬

    cout << minTime(n, p);
    return 0;
}