#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pq;
    while(n--) { // 연산 실행
        cin >> x;
        if(x == 0) { // 1. 가장 작은 수 출력
            // 1-1. 우선순위 큐가 비어있는 경우 0 출력
            if(pq.empty()) { cout << 0 << '\n'; }
            // 1-2. 가장 작은 값 출력하고 우선순위 큐에서 그 값 제거
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x); // 2. 우선순위 큐에 x 넣기
    }
    return 0;
}