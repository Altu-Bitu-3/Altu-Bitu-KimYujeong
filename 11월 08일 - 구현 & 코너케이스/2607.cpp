#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

bool isSame(vector<int> w1, vector<int> w2) { // 같은 구성인가
    for(int i = 0; i < SIZE; i++) {
        if(w1[i] != w2[i]) { // 문자 개수가 다름
            return false;
        }
    }
    return true;
}

bool isSimilar(vector<int> w1, vector<int> w2) { // 비슷한 구성인가
    int diff = 0, idx = -1;
    for(int i = 0; i < SIZE; i++) {
        if(w1[i] == w2[i]) continue;

        // 문자 개수 다른 경우
        diff += abs(w1[i]-w2[i]); // 문자 개수 차이

        //비슷한 문자가 될 수 없는 경우
        if(diff > 2) { return false; }
        // idx != -1 : 이전에 문자 구성이 달랐음
        // w1[idx] + w1[i] != w2[idx] + w2[i] : 이전에 달랐던 문자를 이번 문자로 바꾸지 못함
        if(idx != -1 && (w1[idx] + w1[i] != w2[idx] + w2[i])) { return false; }

        idx = i;

    }
    return true;
}

vector<int> makeConf(string word) { // 문자열 구성 만들기
    vector<int> conf(SIZE, 0);
    for(int i = 0; i < word.length(); i++) {
        conf[word[i]-'A']++;
    }
    return conf;
}

int cntSimilar(vector<string> words) {
    int cnt = 0;
    vector<int> first = makeConf(words[0]);

    for(int i = 1; i < words.size(); i++) {
        vector<int> cmp = makeConf(words[i]);
        if(isSame(first, cmp) || isSimilar(first, cmp)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n, ""); // 단어 저장
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << cntSimilar(words);
    return 0;
}