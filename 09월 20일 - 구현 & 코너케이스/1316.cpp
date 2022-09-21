#include <iostream>
#include <map>

using namespace std;

bool isGroupWord(string word) {
    map<char, int> m; // (key: 알파벳, value: 빈도)
    char pre = word[0]; m[pre]++;
    for(int i = 1; i < word.size(); i++) {
        if(word[i] == pre) m[word[i]]++; // 연속해서 같은 문자가 나온 경우
        else if(word[i] != pre && m[word[i]]) return false; // word[i]가 떨어져서 나타난 경우
        else { // 새로운 다른 문자가 나온 경우
            pre = word[i];
            m[word[i]]++;
        }
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