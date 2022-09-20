#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int INF = 15 * 200 + 1;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

int cost(int n, vector<pi> seed, vector<vector<int>> ground) { // (seed : 3개의 씨앗 위치)
    int cost = 0; // 화단 대여 비용 저장
    vector<vector<bool>> visited (n, vector<bool> (n, false)); // 방문 여부 체크 (true인 좌표를 다시 방문하는 경우 꽃잎 죽음)

    for(int i = 0; i < 3; i++) {
        int row = seed[i].first, col = seed[i].second; // 씨앗 위치
        if(visited[row][col]) return INF; // 다른 꽃잎과 닿음 -> 죽음
        visited[row][col] = true; // 방문 체크

        cost += ground[row][col];
        for(int j = 0; j < 4; j++) {
            int new_row = row + dy[j], new_col = col + dx[j];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n || visited[new_row][new_col]) return INF; // 화단 밖으로 나가거나 다른 꽃잎과 닿음 -> 죽음
            visited[new_row][new_col] = true;
            cost += ground[new_row][new_col];
        }
    }
    return cost;
}

int plant(int n, vector<vector<int>> ground) {
    int answer = INF; // 최소 비용 저장

    vector<pi> cor; // 좌표 정보 저장
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cor.push_back({i, j});
        }
    }

    for(int i = 0; i < n*n; i++) {
        for(int j = i+1; j < n*n; j++) {
            for(int k = j+1; k < n*n; k++) {
                vector<pi> seed = {cor[i], cor[j], cor[k]}; // 3개의 씨앗 위치
                answer = min(answer, cost(n, seed, ground));
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ground (n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 화단의 지점당 가격
        for(int j = 0; j < n; j++)
            cin >> ground[i][j];
    }

    cout << plant(n, ground);
    return 0;
}