#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;

bool isGroupWord(string word) {
    vector<int> visited(SIZE, 0);
    char pre = word[0];
    visited[word[0]-'a'] = true;
    for(int i = 1; i < word.size(); i++) {
        if(!visited[word[i]-'a']) { // 새로운 다른 문자가 나온 경우
            pre = word[i];
            visited[word[i]-'a'] = true;
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