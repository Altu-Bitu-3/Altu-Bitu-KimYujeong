#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5+1;
vector<int> pole; // 전봇대 번호 저장

int lis(int n) {
    vector<int> dp(n, INF); // dp[i] : 최장 부분 수열의 길이가 i일 때 전봇대 번호

    for(int i = 0; i < n; i++) {
        int left = 0, right = n;
        while(left < right) {
            int mid = (left + right) / 2;

            if(dp[mid] > pole[i]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        dp[right] = pole[i]; // 최장 부분 수열의 길이가 right일 때 마지막 전봇대 번호 (제일 큰 전봇대 번호)
    }

    for(int i = 0; i < n; i++) {
        if(dp[i] == INF) return i;
    }
    return n;
}


int main() {
    int n;
    cin >> n;

    pole.assign(n, 0);
    for(int i = 0; i < n; i++) // 전봇대 번호 입력
        cin >> pole[i];

    cout << n-lis(n);
    return 0;
}