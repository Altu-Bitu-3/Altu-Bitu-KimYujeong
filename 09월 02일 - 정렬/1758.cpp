#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll maxTip(int n, vector<int> tip) {
    ll sum = 0;
    for(int i = 0; i < n; i++) { // (i == 받은 등수 - 1)
        int cost = tip[i] - i;
        if(cost < 0) continue; // 팁을 주지 않는 경우
        sum += cost;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> tip (n, 0); // 팁 저장하는 벡터
    for(int i = 0; i < n; i++) // 팁 입력
        cin >> tip[i];
    sort(tip.begin(), tip.end(), greater<>()); // 내림차순 정렬

    cout << maxTip(n, tip);
    return 0;
}