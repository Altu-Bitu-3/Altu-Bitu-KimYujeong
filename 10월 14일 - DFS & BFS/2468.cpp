#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100, MIN = 1; // 최대 높이와 최소 높이
typedef pair<int, int> pi;

int n;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
vector<vector<int>> height; // 해당 지점의 높이

void bfs(int sr, int sc, int rain, vector<vector<bool>> &visited) { // (sr, sc : 그래프 탐색 시작 지점, rain: 비의 양)
    queue<pi> q;
    q.push({sr, sc}); visited[sr][sc] = true; // 시작 지점 방문 check

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n || visited[new_row][new_col]) continue; // 좌표를 벗어났거나 이미 확인한 지점 pass
            if(height[new_row][new_col] <= rain) continue; // 물에 잠기는 지점 pass

            visited[new_row][new_col] = true; // 방문 check
            q.push({new_row, new_col});
        }
    }
}

int main() {
    int max_rain = MIN, min_rain = MAX, result = 1; // (result == 1 : 아무 지점도 물에 잠기지 않는 경우)
    cin >> n;

    height.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> height[i][j];
            max_rain = max(height[i][j], max_rain);
            min_rain = min(height[i][j], min_rain);
        }
    }

    for(int i = min_rain; i < max_rain; i++) { // i : 강수량
        int safe_area = 0; // 강수량이 i일 때 안전한 영역 개수
        vector<vector<bool>> visited(n, vector<bool> (n, false));

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(height[j][k] > i && !visited[j][k]) { // 물에 잠기지 않고 아직 방문하지 않은 영역인 경우 탐색 시작
                    safe_area++;
                    bfs(j, k, i, visited);
                }
            }
        }
        result = max(safe_area, result);
    }

    cout << result;
    return 0;
}