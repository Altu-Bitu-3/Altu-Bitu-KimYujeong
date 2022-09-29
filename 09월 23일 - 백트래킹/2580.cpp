#include <iostream>

using namespace std;

const int SIZE = 9;
bool complete = false;
bool check_row[SIZE][SIZE+1];
bool check_col[SIZE][SIZE+1];
bool check_square[SIZE][SIZE+1];
int board[SIZE][SIZE];

int squareNum(int row, int col) { // 사각형 번호
    return 3 * (row/3) + col/3;
}

void backtracking(int idx) {
    if(idx == SIZE * SIZE) { // 스도쿠 성공
        complete = true;
        return;
    }

    int row = idx / SIZE, col = idx % SIZE;
    if(board[row][col]) { // 이미 숫자가 있는 경우 pass
        return backtracking(idx + 1);
    }

    for(int i = 1; i <= SIZE; i++) { // i : 대입할 숫자 (1 - 9)
        int square = squareNum(row, col);
        if(check_row[row][i] || check_col[col][i] || check_square[square][i]) continue;
        check_row[row][i] = true;
        check_col[col][i] = true;
        check_square[square][i] = true;
        board[row][col] = i; // (row, col)에 i 집어넣기

        backtracking(idx+1);
        if(complete) { return; } // 스도쿠 완성한 경우 종료

        check_row[row][i] = false;
        check_col[col][i] = false;
        check_square[square][i] = false;
        board[row][col] = 0;
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
            if(!board[i][j]) { continue; }
            check_row[i][board[i][j]] = true;
            check_col[j][board[i][j]] = true;
            check_square[squareNum(i, j)][board[i][j]] = true;
        }
    }

    backtracking(0);
    for(int i = 0; i < SIZE; i++) { // 완성한 스도쿠 출력
        for(int j = 0; j < SIZE; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}