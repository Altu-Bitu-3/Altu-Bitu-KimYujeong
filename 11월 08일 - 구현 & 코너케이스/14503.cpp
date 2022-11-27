#include <iostream>

using namespace std;

const int SIZE = 50;
int n, m, cnt = 0; // 세로 크기, 가로 크기, 청소한 칸 개수
int board[SIZE][SIZE]; // (0: 빈 칸, 1: 벽, 2: 청소 완료)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

void clean(int row, int col, int dir) {
    // 현재 위치 청소
    if(board[row][col] != 2) cnt++;
    board[row][col] = 2;

    for(int i = 0; i < 4; i++) { // 왼쪽 방향부터 차례대로 탐색
        int new_dir = (dir-i+3) % 4;
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir];

        if(board[new_row][new_col] == 0) { // 아직 청소하지 않은 공간 발견
            clean(new_row, new_col, new_dir); // 그 방향으로 회전하고 청소 시작
        }
    }

    // 네 방향 모두 청소가 되어 있거나 벽인 경우 후진
    int back_dir = (dir+2) % 4;
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir];

    // 후진할 수 없는 경우
    if(board[back_row][back_col] == 1) {
        cout << cnt;
        exit(0);
    }
    clean(back_row, back_col, dir); // 방향 유지한 상태로 후진
}

int main() {
    cin >> n >> m;

    int r, c, d; // 로봇 청소기 정보 입력
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) { // 장소 정보 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    clean(r, c, d);
    return 0;
}