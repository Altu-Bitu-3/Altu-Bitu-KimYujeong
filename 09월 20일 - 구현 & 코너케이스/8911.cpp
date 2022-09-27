#include <iostream>

using namespace std;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 상 좌 하 우

void squareArea(int row, int col, int &left, int &right, int &top, int &bottom) {
    left = min(left, col); right = max(right, col);
    top = max(top, row); bottom = min(bottom, row);
}

int moveTurtle(string cmd) { // 거북이 이동시키기
    int left = 1, right = -1, top = -1, bottom = 1;

    int row = 0, col = 0, dir = 0; // 시작 위치 및 초기 방향
    squareArea(row, col, left, right, top, bottom); // 사각형 영역 갱신

    for(int i = 0; i < cmd.size(); i++) { // 명령 실행
        switch(cmd[i]) {
            case 'F': // 한 눈금 앞으로 : 현재 방향에서 앞으로 한 칸
                row += dy[dir]; col += dx[dir];
                break;
            case 'B': { // 한 눈금 뒤로 : 현재 방향과 반대로 앞으로 한 칸 (방향은 전환하지 않음)
                int back = (dir + 2) % 4;
                row += dy[back];
                col += dx[back];
                break;
            }
            case 'L': // 왼쪽으로 90도 회전
                dir = (dir + 1) % 4; break;
            case 'R': // 오른쪽으로 90도 회전
                dir = (dir + 3) % 4; break;
        }
        squareArea(row, col, left, right, top, bottom); // (이동시켰으니 사각형 영역 갱신)
    }
    return (right - left) * (top - bottom);
}

int main() {
    int t;
    cin >> t;

    string cmd;
    while(t--) { // 테스트케이스
        cin >> cmd; // 컨트롤 프로그램 입력
        cout << moveTurtle(cmd) << '\n';
    }
    return 0;
}