#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, num;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<>> pq; // (top이 가장 작은 수를 가리킴)
    for(int i = 0; i < n*n; i++) {
        cin >> num;
        pq.push(num);
        // pq는 항상 크기를 n으로 유지, top은 항상 n번째로 큰 수 가리킴
        if(pq.size() > n) pq.pop();
    }

    cout << pq.top(); // n번째로 큰 수 출력
    return 0;
}