#include <string>
#include <vector>

using namespace std;

vector<vector<vector<bool>>> map;

bool validate(int n, int x, int y, int a) {
    if(a) { // 보
        if(y > 0 && map[x][y-1][0]) return true; // 왼쪽 끝이 기둥 위에 있는 경우
        if(y > 0 && x < n && map[x+1][y-1][0]) return true; // 오른쪽 끝이 기둥 위에 있는 경우
        if(x > 0 && x < n && map[x-1][y][1] && map[x+1][y][1]) return true; // 양쪽 끝 모두 다른 보와 연결된 경우
        return false;
    }
    else { // 기둥
        if(y == 0) return true; // 바닥 위에 있는 경우
        if(map[x][y-1][0]) return true; // 다른 기둥 위에 있는 경우
        if((x > 0 && map[x-1][y][1]) || (map[x][y][1])) return true; // 보 한쪽 끝 위에 있는 경우
        return false;
    }
}

bool canDestroy(int n, int x, int y) { // 구조물을 삭제할 수 있는가
    // (x,y) 위치의 구조물을 제거했을 때 주변 구조물들이 온전한가
    int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int nx = x + dx[i], ny = y + dy[j];
            if(nx < 0 || nx > n || ny < 0 || ny > n) continue; // 좌표를 벗어난 경우

            for(int k = 0; k < 2; k++) { // (k: 기둥/보)
                if(map[nx][ny][k] && !validate(n, nx, ny, k)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    map.assign(n+1, vector<vector<bool>> (n+1, vector<bool> (2, false)));

    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0], y = build_frame[i][1];
        int a = build_frame[i][2], b = build_frame[i][3];

        if(b) { // 구조물 설치
            if(validate(n, x, y, a)) { // 설치 가능
                map[x][y][a] = true;
            }
        }
        else { // 구조물 삭제
            map[x][y][a] = false;
            map[x][y][a] = !canDestroy(n, x, y);
        }
    }

    vector<vector<int>> answer;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < 2; k++) {
                if(map[i][j][k]) {
                    answer.push_back({i, j, k});
                }
            }
        }
    }
    return answer;
}