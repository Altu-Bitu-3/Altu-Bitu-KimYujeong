#include <iostream>

using namespace std;

const int INNING = 50, SIZE = 9; // 최대 이닝, 선수 인원
int n, max_score = 0; // 이닝 수, 최고 득점
int result[INNING][SIZE+1]; // 이닝별 결과
int batting_order[SIZE+1]; // 타순
bool assigned[SIZE+1] = { false, }; // 선수 배정 여부 (assigned[i] : i선수 배정 여부)

int move(int hit, bool base[4]) { // hit : 안타 (== 1루타), 2루타, 3루타
    int home = 0; // 홈으로 들어온 인원

    // (3루에 있는 선수부터 이동)
    for(int i = 3; i >= 1; i--) {
        if(base[i]) { // i루에 선수가 있는 경우
            base[i] = false; // i루 비우기
            if(i+hit > 3) { // 홈으로 들어오는 경우
                home++;
            }
            else {
                base[i+hit] = true;
            }
        }
    }

    if(hit == 4) { // 홈런인 경우
        home++; // 타자 홈에 들어옴
    }
    else { // 안타, 2루타, 3루타인 경우
        base[hit] = true; // 타자 베이스 대기
    }
    return home;
}

void game() {
    int score = 0, order = 0; // 점수, 순서

    for(int i = 0; i < n; i++) { // (i : 이닝)
        bool base[4] = { false, }; // 선수 여부 (base[1] : 1루 선수 여부)
        int out = 0; // 아웃 카운트

        while(out < 3) {
            // 다음 타자
            if(++order == 10) order = 1; // (10번 순서는 존재하지 않으므로 다시 1번 순서로)
            int hitter = batting_order[order], hit = result[i][hitter];

            if(hit == 0) { // 아웃 카운트 증가
                out++;
            }
            else { // 선수 이동
                score += move(hit, base);
            }
        }
    }
    max_score = max(score, max_score);
}

void backtracking(int order) {
    if(order > SIZE) { // 기저조건 : 타순 배정 완료
        game(); // 게임 시작
        return;
    }

    if(order == 4) { // (4번 타자 이미 배정 완료)
        backtracking(order+1);
        return;
    }

    // 타순 정하기
    for(int i = 2; i <= SIZE; i++) { // (i : 선수)
        if(assigned[i]) continue; // 이미 배정된 선수 pass
        assigned[i] = true;
        batting_order[order] = i;
        backtracking(order+1);
        assigned[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 4번 타자는 항상 1번 선수
    batting_order[4] = 1;
    assigned[1] = true;

    cin >> n; // 이닝 수 입력
    for(int i = 0; i < n; i++) { // 각 선수 결과 입력
        for(int j = 1; j <= SIZE; j++) {
            cin >> result[i][j];
        }
    }

    backtracking(1);
    cout << max_score; // 최고 득점 출력
    return 0;
}