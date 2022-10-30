#include <iostream>
#include <vector>

using namespace std;

void printSwitch(int n, vector<int> state) { // 스위치 상태 출력
    for(int i = 1; i <= n; i++) {
        cout << state[i] << ' ';
        if(i % 20 == 0) cout << '\n'; // (20개까지 출력 후 줄바꿈)
    }
}

void male(int num, int n, vector<int> &state) { // 남학생 : 배수 스위치 상태 변경
    for(int i = num; i <= n; i += num) { // 스위치 상태 변경
        state[i] = !state[i];
    }
}

void female(int num, int n, vector<int> &state) { // 여학생 : 가장 긴 좌우 대칭 구간 상태 변경
    int left = num, right = num;
    while(left >= 1 && right <= n) {
        if(left-1 < 1 || right+1 > n) break; // 스위치 범위 초과
        if(state[left-1] != state[right+1]) break; // 좌우 대칭이 아닌 경우 break
        left--; right++;
    }

    for(int i = left; i <= right; i++){ // 스위치 상태 변경
        state[i] = !state[i];
    }
}

int main() {
    int n, m, gender, num;

    cin >> n;
    vector<int> state (n+1, 0); // 스위치 상태
    for(int i = 1; i <= n; i++) { // 스위치 상태 입력
        cin >> state[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++) { // 성별, 학생이 받은 수 입력
        cin >> gender >> num;
        if(gender == 1) { // 1. 남학생인 경우
            male(num, n, state);
        }
        else if(gender == 2) { // 2. 여학생인 경우
            female(num, n, state);
        }
    }

    printSwitch(n, state); // 스위치 상태 출력
    return 0;
}