#include <iostream>

using namespace std;

const int SIZE = 8; // 체스판 크기
string king, rock; // 킹과 돌의 위치 정보
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};

int setDirection(string cmd) { // 방향 설정 함수
    if(cmd == "R") return 0;
    if(cmd == "L") return 1;
    if(cmd == "B") return 2;
    if(cmd == "T") return 3;
    if(cmd == "RT") return 4;
    if(cmd == "LT") return 5;
    if(cmd == "RB") return 6;
    if(cmd == "LB") return 7;
}

void move(string cmd) {
    int dir = setDirection(cmd);

    // 현재 킹 위치
    int king_row = king[1] - '0';
    char king_col = king[0];

    // 킹이 이동하려는 칸 위치
    int king_nr = king_row + dy[dir];
    char king_nc = king_col + dx[dir];

    // 1. 킹이 체스판 밖으로 나가는 경우 pass
    if(king_nr <= 0 || king_nr > SIZE || king_nc < 'A' || king_nc > 'H') { return; }

    // 현재 돌 위치
    int rock_row = rock[1] - '0';
    char rock_col = rock[0];
    if(king_nr == rock_row && king_nc == rock_col) { // 2. 킹이 이동하려는 칸에 돌이 있는 경우
        // 돌이 이동하려는 칸 위치
        int rock_nr = rock_row + dy[dir];
        char rock_nc = rock_col + dx[dir];

        // 2-1. 돌이 체스판 밖으로 나가는 경우 pass
        if(rock_nr <= 0 || rock_nr > SIZE || rock_nc < 'A' || rock_nc > 'H') { return; }
        rock = rock_nc + to_string(rock_nr);
    }

    // 3. 킹 위치 이동
    king = king_nc + to_string(king_nr);
}

int main() {
    int n; // 움직이는 횟수
    cin >> king >> rock >> n;

    string cmd; // 움직이는 정보
    while(n--) {
        cin >> cmd;
        move(cmd);
    }

    cout << king << '\n' << rock; // 킹과 돌 위치 정보 출력
    return 0;
}