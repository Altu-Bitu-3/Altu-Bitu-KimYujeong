#include <iostream>
#include <vector>

using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length(), m = s2.length(); // 각각 s1과 s2의 길이
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) { // 1. 같은 문자
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else { // 2. 다른 문자: 그 전의 길이 최댓값 적용
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
    return 0;
}