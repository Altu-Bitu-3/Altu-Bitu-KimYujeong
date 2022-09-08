#include <iostream>

using namespace std;

void addBigNum(string a, string b) { // 큰 수의 덧셈
    string rev_ans = ""; // 덧셈 결과 거꾸로 저장
    int p1 = a.length()-1, p2 = b.length()-1; // 각각 a와 b의 자릿수를 가리키는 포인터

    bool ten = false; // 올림 여부 표시
    while(p1 >= 0 && p2 >= 0) {
        int digit = (a[p1] - '0') + (b[p2] - '0') + ten;
        ten = false;
        if(digit >= 10) { // 올림 필요한 경우
            ten = true;
            digit -= 10;
        }
        rev_ans += to_string(digit);
        p1--; p2--;
    }
    while(p1 >= 0) { // p1의 자릿수가 남아있는 경우
        int digit = (a[p1] - '0') + ten;
        ten = false;
        if(digit >= 10) { // 올림 필요한 경우
            ten = true;
            digit -= 10;
        }
        rev_ans += to_string(digit);
        p1--;
    }
    while(p2 >= 0) { // p2의 자릿수가 남아있는 경우
        int digit = (b[p2] - '0') + ten;
        ten = false;
        if(digit >= 10) { // 올림 필요한 경우
            ten = true;
            digit -= 10;
        }
        rev_ans += to_string(digit);
        p2--;
    }
    if(ten) rev_ans += '1'; // 올림이 남아있는 경우 1 추가

    for(int i = rev_ans.length()-1; i >= 0; i--) // 거꾸로 된 답안 바르게 출력
        cout << rev_ans[i];
}

int main() {
    string a, b;
    cin >> a >> b;

    addBigNum(a, b);
    return 0;
}