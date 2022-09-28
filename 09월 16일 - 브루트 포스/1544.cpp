#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool isCycleWord(string s1, string s2) { // s1과 s2는 같은 단어인가
    if(s1.length() != s2.length()) return false; // 길이가 같지 않은 경우, 사이클 단어 아님

    int len = s1.length();
    for(int i = 0; i < len; i++) {
        if(s1 == s2) return true; // 사이클 문자 (== 같은 문자)인 경우

        // 0번 인덱스의 문자 지우고 문자열 맨 뒤에 push
        char front = s2.front();
        s2 = s2.erase(0, 1);
        s2.push_back(front);
    }
    return false;
}

int cntCycleWords(int n, vector<string> words) { // 서로 다른 개수 세기
    set<string> s; // 서로 다른 단어 저장하는 셋

    for(int i = 0; i < n; i++) {
        bool cycle = false;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            if(isCycleWord(*iter, words[i])) {
                cycle = true;
                break;
            }
        }
        if(!cycle) s.insert(words[i]); // 서로 다른 단어 찾음
    }
    return s.size();
}

int main() {
    int n;
    cin >> n;

    vector<string> words (n, "");
    for(int i = 0; i < n; i++) // 단어 입력
        cin >> words[i];

    cout << cntCycleWords(n, words);
    return 0;
}