#include <iostream>

using namespace std;

const int SIZE = 10, INF = 1e8;
int answer = INF + 1;
int w[SIZE][SIZE]; // 비용
bool visited[SIZE]; // 방문 여부

void backtracking(int start, int prev, int cnt, int sum, int n) {
    if(cnt == n-1) {
        if(!w[prev][start]) return; // 원점으로 돌아갈 수 없는 경우 pass
        sum += w[prev][start];
        answer = min(answer, sum);
        return;
    }

    for(int i = 0; i < n; i++) {
        // 이미 방문한 도시거나 길이 없거나 곧바로 원점으로 가는 경우 pass
        if(visited[i] || !w[prev][i] || i == start) continue;
        visited[i] = true; // 방문 체크
        backtracking(start, i, cnt+1, sum + w[prev][i], n);
        visited[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) { // 비용 입력
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    for(int i = 0; i < n; i++) { // i : 시작 지점
        backtracking(i, i, 0, 0, n);
    }
    cout << answer;
    return 0;
}