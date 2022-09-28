#include <iostream>
#include <stack>

using namespace std;

void backspace(stack<char> &s1) { // 백스페이스
    if(!s1.empty()) s1.pop();
}

void leftCursor(stack<char> &s1, stack<char> &s2) { // 왼쪽 커서
    if(!s1.empty()) {
        char top = s1.top(); s1.pop();
        s2.push(top);
    }
}

void rightCursor(stack<char> &s1, stack<char> &s2) { // 오른쪽 커서
    if(!s2.empty()) {
        char top = s2.top(); s2.pop();
        s1.push(top);
    }
}

string findPassword(string input) { // 비밀번호 찾기
    stack<char> s1, s2;
    for(int i = 0; i < input.length(); i++) {
        switch(input[i]) {
            case '-' : // 바로 앞 글자 지우기
                backspace(s1);
                break;
            case '<' : // 왼쪽으로 이동
                leftCursor(s1, s2);
                break;
            case '>' : // 오른쪽으로 이동
                rightCursor(s1, s2);
                break;
            default: s1.push(input[i]); // 패스워드를 구성하는 문자는 바로 push
        }
    }

    string password = "", rev_password = "";

    // (s1에 들어있는 문자들 == 거꾸로 저장된 비밀번호)
    while(!s1.empty()) {
        rev_password += s1.top();
        s1.pop();
    }
    for(int i = rev_password.length()-1; i >= 0; i--)
        password += rev_password[i];

    while(!s2.empty()) {
        password += s2.top();
        s2.pop();
    }
    return password;
}

int main() {
    int t;
    cin >> t;

    string input;
    while(t--) {
        cin >> input;
        cout << findPassword(input) << '\n';
    }
    return 0;
}