#include <iostream>
#include <vector>

using namespace std;

int maxWine(int n, vector<int> wine) { // 최대로 마실 수 있는 포도주의 양
    vector<int> dp(n+1, 0);
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++) {
        // i-2 마시지 않음 : wine[i] + wine[i-1] + dp[i-3]
        // i-1 마시지 않음 : wine[i] + dp[i-2]
        // i 마시지 않음 : dp[i-1]
        dp[i] = max(max(wine[i] + wine[i-1] + dp[i-3], wine[i] + dp[i-2]), dp[i-1]);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> wine(n+1, 0);
    for(int i = 1; i <= n; i++) // 포도주 양 입력
        cin >> wine[i];

    cout << maxWine(n, wine);
    return 0;
}