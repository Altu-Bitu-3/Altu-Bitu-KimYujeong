#include <iostream>
#include <vector>

using namespace std;

int lis(int n, vector<int> a) {
    vector<int> dp(n, 1); // (lis의 최솟값은 1이므로 1로 초기화)
    for(int i = 0; i < n; i++) { // (j < i)
        for(int j = 0; j < i; j++) {
            // 증가하는 수열 발견
            if(a[i] > a[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    int answer = 0; // 가장 긴 증가하는 부분 수열 길이 저장
    for(int i = 0; i < n; i++) {
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) // 수열 A 입력
        cin >> a[i];

    cout << lis(n, a);
    return 0;
}