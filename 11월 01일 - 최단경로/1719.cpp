#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 * 2;
vector<vector<int>> graph, path;

void floydWarshall(int n) {
    for(int k = 1; k <= n; k++) { // k : 중간 지점
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                if(graph[i][j] > dist) {
                    graph[i][j] = dist;
                    path[i][j] = path[i][k]; // (k가 중간 지점이므로) == k로 가기 위해 가장 먼저 방문하는 정점
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n+1, vector<int> (n+1, INF));
    path.assign(n+1, vector<int> (n+1, INF));
    for(int i = 1; i <= n; i++) { graph[i][i] = 0; }

    int u, v, w;
    while(m--) { // 경로 입력
        cin >> u >> v >> w;

        // 양방향 그래프
        graph[u][v] = w;
        graph[v][u] = w;

        // 가장 먼저 방문하는 정점
        path[u][v] = v;
        path[v][u] = u;
    }

    floydWarshall(n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) cout << "- ";
            else cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}