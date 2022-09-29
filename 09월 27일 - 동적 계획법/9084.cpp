#include <iostream>
#include <vector>

using namespace std;

int makeM(int n, int m, vector<int> coin) { // m원 만드는 경우의 수
    vector<int> dp(m+1, 0);

    dp[0] = 1; // (0원을 만드는 경우의 수는 1개)
    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= m; j++) {
            dp[j] += dp[j-coin[i]];
        }
    }
    return dp[m];
}

int main() {
    int t, n, m;
    cin >> t;

    while(t--) {
        cin >> n; // 동전 개수 입력
        vector<int> coin(n, 0);
        for(int i = 0; i < n; i++) // 동전 금액 입력
            cin >> coin[i];
        cin >> m; // 목표 금액 입력
        cout << makeM(n, m, coin) << '\n';
    }
    return 0;
}