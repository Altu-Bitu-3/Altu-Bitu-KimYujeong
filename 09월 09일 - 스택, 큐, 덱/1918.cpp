#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) { // 연산자 우선순위 (0 - 1 - 2 순으로 쌓을 수 있음)
    switch(ch) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

string postOrder(string inorder) { // 후위 연산식으로 변환
    string result = "";

    stack<char> op; // 연산자 저장하는 스택
    for(int i = 0; i < inorder.length(); i++) {
        switch(inorder[i]) {
            case '(': // 1. 여는 괄호 : 무조건 push
                op.push(inorder[i]);
                break;
            case ')': // 2. 닫는 괄호 : 여는 괄호 나올 때까지 pop
                while(!op.empty() && op.top() != '(') {
                    result += op.top();
                    op.pop();
                }
                op.pop();
                break;
            case '+': case '-':
            case '*': case '/': // 3. 연산자 : 연산자 우선순위 낮은 거 발견하기 전까지 pop
                while(!op.empty() && priority(inorder[i]) <= priority(op.top())) {
                    result += op.top();
                    op.pop();
                }
                op.push(inorder[i]);
                break;
            default: result += inorder[i]; // 4. 피연산자 : 그대로 넣기

        }
    }

    while(!op.empty()) {
        result += op.top();
        op.pop();
    }
    return result;
}

int main() {
    string inorder;
    cin >> inorder; // 중위 표기식 입력

    cout << postOrder(inorder); // 후위 표기식 출력
    return 0;
}