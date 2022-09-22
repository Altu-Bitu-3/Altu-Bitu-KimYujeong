#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;
int alphabet[SIZE]; // 알파벳 개수 저장

string palindrome(string input) {
    int len = input.size(), mid = len/2;
    for(int i = 0; i < len; i++) alphabet[input[i]-'A']++;

    vector<char> result (len, '\0');
    for(int i = 0; i < mid; i++) { // (mid까지는 2이상의 수가 필요함)
        for(int j = 0; j < SIZE; j++) {
            if(alphabet[j] >= 2) {
                result[i] = result[len-1-i] = 'A' + j;
                alphabet[j] -= 2;
                break;
            }
        }
        // i 자리에 넣을 수 있는 수가 없는 경우, 팰린드롬 아님
        if(result[i] == '\0') return "I'm Sorry Hansoo";
    }

    if(len % 2) { // 홀수인 경우, (mid + 1) 자리에 문자 넣기
        for(int i = 0; i < SIZE; i++) {
            if(alphabet[i]) {
                result[mid] = 'A' + i;
                break;
            }
        }
    }

    string answer = ""; // 정답 만들기
    for(int i = 0; i < len; i++) answer += result[i];
    return answer;
}

int main() {
    string input;
    cin >> input;

    cout << palindrome(input);
    return 0;
}