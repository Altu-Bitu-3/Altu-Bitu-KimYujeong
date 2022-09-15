#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> josephus(int n, int k) {
    vector<int> remove; // 제거되는 순서 저장

    queue<int> q; // 원을 이루는 사람들
    for(int i = 1; i <= n; i++) q.push(i);

    int cnt = 0; // 순서 저장
    while(!q.empty()) {
        int person = q.front(); q.pop();
        if(++cnt % k == 0) remove.push_back(person); // k번째 사람 제거
        else q.push(person); // pop한 사람 다시 push
    }
    return remove;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ans = josephus(n, k);

    // 정답 출력
    cout << '<';
    for(int i = 0; i < n-1; i++)
        cout << ans[i] << ", ";
    cout << ans[n-1] << '>';
    return 0;
}