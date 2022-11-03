#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e8 * 2;
vector<vector<pi>> graph; // (first : 정점, second : 거리)

vector<int> dijkstra(int s, int n) { // (s: 시작 정점)
    vector<int> dist(n+1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq; // (first : 거리, second : 정점)

    dist[s] = 0; pq.push({0, s});

    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 방문한 정점 pass

        for(int i = 0; i < graph[node].size(); i++) { // node에서 다른 정점 방문하기
            int new_node = graph[node][i].first;
            int new_weight = weight + graph[node][i].second;
            if(dist[new_node] > new_weight) {
                dist[new_node] = new_weight;
                pq.push({new_weight, new_node});
            }
        }
    }
    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.assign(n+1, vector<pi> (0));
    int a, b, c;
    while(e--) { // 간선 정보 입력
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2; // 반드시 거쳐야 하는 두 개의 정점
    cin >> v1 >> v2;

    vector<int> from_1 = dijkstra(1, n);
    vector<int> from_v1 = dijkstra(v1, n);
    vector<int> from_v2 = dijkstra(v2, n);
    int from_v1_to_v2 = from_v1[v2], from_v2_to_v1 = from_v2[v1];

    int answer = INF;
    // 코스 1) 1 -> v1 -> v2 -> n
    int course1 = from_1[v1] + from_v1_to_v2 + from_v2[n];
    // 코스 2) 1 -> v2 -> v1 -> n
    int course2 = from_1[v2] + from_v2_to_v1 + from_v1[n];
    answer = min(answer, min(course1, course2));
    if(answer == INF) cout << -1;
    else cout << answer;
    return 0;
}