#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e7;

pi hack(int c, int n, vector<vector<pi>> computer) {
    vector<int> time (n+1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq; // (first : 시간, second : 컴퓨터 번호)
    time[c] = 0; pq.push({0, c}); // 해킹된 컴퓨터

    int cnt = 0, max_time = 0; // 감염된 컴퓨터 수, 최대로 걸린 시간
    while(!pq.empty()) {
        int b = pq.top().second; // 컴퓨터 b
        int s = pq.top().first; // b가 감염되기까지 걸린 시간
        pq.pop();

        if(s > time[b]) { continue; } // 이미 감염된 컴퓨터 pass
        if(time[b] != INF) {
            cnt++; // 감염된 컴퓨터 세기
            max_time = max(max_time, time[b]);
        }
        
        for(int i = 0; i < computer[b].size(); i++) { // b가 a 컴퓨터 감염시키기
            int a = computer[b][i].second;
            int new_s = s + computer[b][i].first; // a가 감염되기까지 걸린 시간
            if(time[a] > new_s) {
                time[a] = new_s;
                pq.push({new_s, a});
            }
        }
    }
    return {cnt, max_time};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) { // 테스트 케이스
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pi>> computer (n+1, vector<pi> (0)); // (first : 시간, second : 컴퓨터 번호)
        int a, b, s;
        while(d--) { // 의존성 입력
            cin >> a >> b >> s;
            computer[b].push_back({s, a});
        }

        pi result = hack(c, n, computer);
        cout << result.first << ' ' << result.second << '\n';
    }
    return 0;
}