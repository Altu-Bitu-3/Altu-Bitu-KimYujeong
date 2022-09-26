#include <iostream>
#include <set>

using namespace std;

bool isGroupWord(string word) {
    set<char> s;
    char pre = word[0]; s.insert(word[0]);
    for(int i = 1; i < word.size(); i++) {
        if(s.find(word[i]) == s.end()) { // 새로운 다른 문자가 나온 경우
            pre = word[i];
            s.insert(word[i]); // set에 새로운 문자 추가
        }
        else if(word[i] != pre) return false; // set에 존재하는 문자가 떨어져서 나타난 경우
    }
    return true;
}

int main() {
    int n, cnt = 0;
    cin >> n;

    string word;
    while(n--) {
        cin >> word;
        cnt += isGroupWord(word);
    }
    cout << cnt;
    return 0;
}