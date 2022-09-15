#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cntOperation(string input) {
    int cnt = 0;

    stack<char> s;
    for(int i = 0; i < input.length(); i++) {
        // 1. 여는 괄호 무조건 push
        if(input[i] == '{') s.push(input[i]);
        // 2. 닫는 괄호 나온 경우, 연산 실행
        else if(input[i] == '}') {
            if(s.empty()) { // 2-1. 불안정적 : 여는 괄호로 변환
                cnt++;
                s.push('{');
            }
            else s.pop(); // 2-2. 안정적
        }
    }
    cnt += s.size()/2;
    return cnt;
}

int main() {
    string test; // 입력 데이터
    int test_no = 0; // 테스트케이스 번호
    while(true) {
        getline(cin, test);
        if(test.find('-') != string::npos) break; // 종료 조건
        cout << ++test_no << ". " << cntOperation(test) << '\n';
    }
    return 0;
}