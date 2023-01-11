#include <iostream>
#include <vector>

using namespace std;

int maxCandy(int n, int m, vector<vector<int>> room) {
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // dp[i-1][j] : 아래로 이동
            // dp[i][j-1] : 오른쪽으로 이동
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + room[i][j];
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> room(n+1, vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++) { // 사탕 개수 입력
        for(int j = 1; j <= m; j++)
            cin >> room[i][j];
    }

    cout << maxCandy(n, m, room);
    return 0;
}