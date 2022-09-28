#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e9, MIN = -1e9;
int max_result = MIN, min_result = MAX;

void backtracking(int idx, int n, int result, vector<int> a, vector<int> op) {
    if(idx == n) { // n개의 수 모두 사용 완료
        max_result = max(max_result, result);
        min_result = min(min_result, result);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            int next_result = result; // 다음 결과값 저장
            switch(i) {
                case 0: next_result += a[idx]; break; // 덧셈
                case 1: next_result -= a[idx]; break; // 뺄셈
                case 2: next_result *= a[idx]; break; // 곱셈
                case 3: next_result /= a[idx]; break; // 나눗셈
            }
            op[i]--;
            backtracking(idx+1, n, next_result, a, op);
            op[i]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) // A 입력
        cin >> a[i];

    vector<int> op(4, 0);
    for(int i = 0; i < 4; i++) // 연산자 개수 입력
        cin >> op[i];

    backtracking(1, n, a[0], a, op);
    cout << max_result << '\n' << min_result;
    return 0;
}