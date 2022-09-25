#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 10;
int answer = 0;
int check[SIZE]; // 수 사용 여부
set<vector<string>> s; // n 만드는 과정 저장하는 셋

void setDigit(string target) { // 수 세팅
    for(int i = 0; i < target.length(); i++) {
        check[target[i]-'0']++;
    }
}

void backtracking(string result, string target, vector<string> proceed) {
    proceed.push_back(result);
    if(result.length() == target.length()) {
        // n 만들기 성공 && 과정도 다름
        if(result == target && s.find(proceed) == s.end()) {
            answer++;
            s.insert(proceed);
        }
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(check[i]) {
            check[i]--;
            // 왼쪽에 숫자 하나 적기
            backtracking(to_string(i) + result, target, proceed);
            // 오른쪽에 숫자 하나 적기
            backtracking(result + to_string(i), target, proceed);
            check[i]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    string target = to_string(n);
    setDigit(target); // 숫자 세팅하기

    backtracking("", target, {});
    cout << answer;
    return 0;
}