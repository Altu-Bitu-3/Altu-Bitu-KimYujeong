#include <iostream>

using namespace std;

const int SIZE = 9;
int digit[SIZE+1] = {0, }; // digit[i] : i의 개수

bool isMultiple30() { // 30의 배수 여부 판단 : 30의 배수는 각 자리수의 합이 3의 배수
    int sum = 0;
    for(int i = 0; i <= SIZE; i++) {
        sum += (i * digit[i]);
    }
    if(sum%3) return false;
    return true;
}

string mirco() { // 미르코가 만들고 싶어하는 수가 존재하는가
    if(!digit[0]) return "-1"; // 0이 하나라도 존재하지 않는 경우
    if(!isMultiple30()) return "-1"; // 30의 배수가 아닌 경우

    // 30의 배수가 되는 가장 큰 수 만들기
    string answer = "";
    for(int i = SIZE; i >= 0; i--) {
        char num = (i+'0');
        for(int j = 0; j < digit[i]; j++) {
            answer += num;
        }
    }
    return answer;
}

int main() {
    string n;
    cin >> n;

    for(int i = 0; i < n.length(); i++) {
        digit[n[i]-'0']++;
    }
    cout << mirco();
    return 0;
}