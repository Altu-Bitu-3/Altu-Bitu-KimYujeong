#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> t; // 심사 소요 시간

ll cntPass(ll k, int n) { // k시간동안 몇 명이 심사 받을 수 있는가
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (k/t[i]);
    }
    return cnt;
}

ll binarySearch(ll left, ll right, int n, int m) {
    ll answer = 0;
    while(left <= right) {
        ll mid = (left + right) / 2; // 심사 소요 시간
        ll pass = cntPass(mid, n); // mid 시간동안 심사 받은 사람 수

        if(pass >= m) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    t.assign(n, 0);
    for(int i = 0; i < n; i++) // 심사 소요 시간 입력
        cin >> t[i];
    sort(t.begin(), t.end()); // 심사 소요 시간 오름차순 정렬

    cout << binarySearch(t[0], (ll)t[n-1] * m, n, m);
    return 0;
}