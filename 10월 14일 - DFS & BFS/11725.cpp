#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edge;

vector<int> bfs(int n) {
    vector<int> result (n+1, 0); // 각 노드의 부모 정보 저장
    queue<int> q;
    q.push(1); result[1] = 1; // 루트 노드

    while(!q.empty()) {
        int parent = q.front(); q.pop();

        for(int i = 0; i < edge[parent].size(); i++) {
            int node = edge[parent][i];

            // result[node] == 0 : 자식 / result[node] != 0 : 부모
            if(!result[node]) { // 자식 찾음
                result[node] = parent;
                q.push(node);
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    edge.assign(n+1, vector<int> (0, 0));
    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        // (어느 노드가 부모 노드인지 모름 -> 무방향 그래프)
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> result = bfs(n);
    for(int i = 2; i <= n; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}