#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct info{
    int row, col, time, dist; // (row, col)까지 이돟하는 데 걸린 시간
};
int n, answer = 0;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우
map<int, int> shark; // (상어 크기, 상어가 잡아먹은 물고기 수)

bool cmp(const info &i1, const info &i2) {
    if(i1.row != i2.row) return i1.row < i2.row;
    return i1.col < i2.col;
}

// 상어 위치 : (sr, sc) / 상어 크기 : size
void bfs(int sr, int sc, int size, int time, vector<vector<int>> &board) {
    answer = max(answer, time);
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // 방문 여부 저장

    vector<info> fish; // 먹이 후보
    queue<info> q;
    q.push({sr, sc, time, 0});

    while(!q.empty()) {
        int r = q.front().row, c = q.front().col;
        int t = q.front().time, d = q.front().dist; q.pop();
        if(visited[r][c]) { // 이미 방문한 칸 pass
            continue;
        }
        visited[r][c] = true; // 방문 체크

        if(fish.size() && fish[0].dist != d+1) { // 더 가까운 먹이 찾을 수 없음
            break;
        }

        for(int i = 0; i < 4; i++) { // 인접한 좌표 탐색
            int nr = r + dy[i], nc = c + dx[i];

            // 이미 방문한 정점이거나 좌표를 벗어난 경우
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                continue;
            }

            // 1. 지나갈 수 없는 칸
            if(board[nr][nc] > size) { // 자신의 크기보다 큰 물고기
                continue;
            }
            // 2. 지나갈 수 있는 칸 (== 이동 가능 -> 1초 소요)
            if(board[nr][nc] && board[nr][nc] < size) { // 2-1. 자신의 크기보다 작은 물고기
                fish.push_back({nr, nc, t+1, d+1});
            }
            else { // 2-2. 자신의 크기와 같은 물고기 혹은 빈칸
                q.push({nr, nc, t+1, d+1});
            }
        }
    }

    if(fish.size()) { // 물고기 잡아먹을 수 있는 경우 -> 잡아먹고 이동
        sort(fish.begin(), fish.end(), cmp);

        int nr = fish[0].row, nc = fish[0].col;
        board[nr][nc] = 0;

        if(++shark[size] == size) { // 상어 성장
            bfs(nr, nc, size+1, fish[0].time, board);
        }
        else {
            bfs(nr, nc, size, fish[0].time, board);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n; // 공간 크기 입력

    int sr, sc; // 아기 상어 위치 저장
    vector<vector<int>> board(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 공간 상태 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) { // 아기 상어 위치 설정
                sr = i;
                sc = j;
                board[i][j] = 0;
            }
        }
    }

    bfs(sr, sc, 2, 0, board);
    cout << answer;
    return 0;
}