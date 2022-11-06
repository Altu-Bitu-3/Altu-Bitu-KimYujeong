#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void bfs(int sr, int sc, int m, int n, vector<vector<bool>> &cabbage) {
    queue<pi> q;
    q.push({sr, sc}); cabbage[sr][sc] = false; // 시작 지점 방문 check

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m || !cabbage[new_row][new_col]) continue; // 좌표를 벗어났거나 양배추가 없는 경우 pass

            cabbage[new_row][new_col] = false; // 방문 check
            q.push({new_row, new_col});
        }
    }
}

int main() {
    int t, m, n, k;

    cin >> t;
    while(t--) { // 테스트 케이스
        cin >> m >> n >> k;
        vector<vector<bool>> cabbage (n, vector<bool> (m, false));

        int x, y;
        while(k--) { // 배추 위치 입력
            cin >> x >> y;
            cabbage[y][x] = true;
        }

        int cnt = 0; // 지렁이 개수
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(cabbage[i][j]) { // 배추 발견, 그래프 탐색
                    cnt++;
                    bfs(i, j, m, n, cabbage);
                }
            }
        }
        cout << cnt << '\n'; // 지렁이 개수 출력
    }
    return 0;
}