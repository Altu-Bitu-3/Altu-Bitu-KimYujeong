#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<int> pq;

int docOrder(int m, queue<pi> q, pq documents) {
    int order = 0; // 문서 출력 순서
    while(!q.empty()) {
        if(q.front().first == documents.top()) { // 1. 바로 출력할 수 있는 문서
            order++;
            if(q.front().second == m) return order; // m번째 문서인 경우 순서 반환
            q.pop(); documents.pop();
        }
        else { // 2. 바로 출력할 수 없는 문서 (큐의 가장 앞에 있는 문서보다 더 높은 중요도를 가진 문서가 존재함)
            // 맨 뒤로 보내기
            q.push(q.front());
            q.pop();
        }
    }
}

int main() {
    int t, n, m, importance;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        queue<pi> q; // (first : 문서 중요도, second: 문서 번호)
        pq documents; // (top이 가장 높은 중요도를 가진 문서 가리킴)
        for(int i = 0; i < n; i++) { // 문서 중요도 입력
            cin >> importance;
            q.push({importance, i});
            documents.push(importance);
        }
        cout << docOrder(m, q, documents) << '\n';
    }
    return 0;
}