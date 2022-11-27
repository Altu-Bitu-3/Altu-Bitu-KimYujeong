#include <string>
#include <vector>

using namespace std;

const int INF = 1e7 * 2;
vector<vector<int>> graph;

void setFare(int n, vector<vector<int>> fares) { // 그래프 요금 세팅
    graph.assign(n+1, vector<int> (n+1, INF));
    for(int i = 1; i <= n; i++) { // i지점에서 i지점으로 이동하는 요금은 0원
        graph[i][i] = 0;
    }

    int size = fares.size();
    for(int i = 0; i < size; i++) {
        int c = fares[i][0], d = fares[i][1], f = fares[i][2];
        // 양방향 그래프 (c와 d지점 사이의 택시 요금 f)
        graph[c][d] = f;
        graph[d][c] = f;
    }
}

void floydWarshall(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], dist);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) { // 지점 개수 : n, 출발 지점 : s
    setFare(n, fares); // 요금 세팅
    floydWarshall(n);

    int answer = INF;
    for(int i = 1; i <= n; i++) { // i지점까지 합승
        int cost = graph[s][i] + graph[i][a] + graph[i][b];
        answer = min(answer, cost);
    }
    return answer;
}