#include <iostream>
#include <vector>

using namespace std;

void rotate(int n, vector<int> &belt, vector<bool> &robot) { // 벨트와 로봇 한 칸 회전
    belt[0] = belt[2*n]; // (2n번째 칸을 1칸으로 올리기 위함)
    for(int i = 2*n-1; i >= 0; i--) {
        belt[i+1] = belt[i];
        robot[i+1] = robot[i];
    }
    robot[n] = false; // 로봇 내리기
}

void moveRobot(int n, vector<int> &belt, vector<bool> &robot) { // 로봇 이동하기
    for(int i = n-1; i >= 1; i--) {
        if(robot[i] && !robot[i+1] && belt[i+1]) { // i칸에 위치한 로봇이 한 칸 이동할 수 있는 경우
            belt[i+1]--;
            robot[i] = false; robot[i+1] = true;
        }
    }
    robot[n] = false; // 로봇 내리기
}

void upRobot(vector<int> &belt, vector<bool> &robot) {
    if(!belt[1]) return; // 내구도 0인 경우 로봇 올리지 못함
    robot[1] = true;
    belt[1]--;
}

int cntZero(int n, vector<int> belt) { // 내구도 0인 칸 개수 세기
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++) {
        if(!belt[i]) cnt++;
    }
    return cnt;
}

int cntRound(int n, int k, vector<int> belt) {
    int round = 0;
    vector<bool> robot(2*n+1, false);

    while(true) {
        round++;
        rotate(n, belt, robot); // 로봇과 함께 회전
        moveRobot(n, belt, robot); // 로봇 이동
        upRobot(belt, robot); // 로봇 올리기
        if(cntZero(n, belt) >= k) break; // 종료 조건
    }
    return round;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> belt(2*n+1, 0);
    for(int i = 1; i <= 2*n; i++)
        cin >> belt[i];

    cout << cntRound(n, k, belt);
    return 0;
}