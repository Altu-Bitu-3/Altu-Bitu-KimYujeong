#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

map<int, int> getNumSet(string input) {
    map<int, int> m; // (key: 주어진 정수, value: 개수)
    string num = "";
    for(int i = 0; i < input.length(); i++) {
        // 1. 빈 칸 나온 경우 -> 집합에 숫자 집어넣기
        if(input[i] == ' ') {
            m[stoi(num)]++;
            num = "";
        }
        // 2. 숫자 이어 붙이기
        else num += input[i];
    }
    m[stoi(num)]++; // 마지막 숫자 집어넣기
    return m;
}

vector<pi> findPair(string input, int sum) { // 서로 다른 위치에 있는 두 수의 쌍의 합이 sum인 쌍 반환
    vector<pi> pair; // 두 수의 쌍 저장
    map<int, int> m = getNumSet(input); // (서로 다른 위치에 있는 정수가 같을 수 있기 때문에 map 이용)

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        int a = iter->first;
        m[a]--;
        for(auto iter_ = iter; iter_ != m.end(); iter_++) {
            int b = iter_->first;
            if(m[b] > 0 && a + b == sum) pair.push_back({a, b}); // 쌍 발견
        }
        m[a]++;
    }
    return pair;
}

int main() {
    string input;
    getline(cin, input); // 문자열 한 줄 입력받기

    int sum;
    cin >> sum;

    vector<pi> pair = findPair(input, sum);
    int cnt = pair.size();
    for(int i = 0; i < cnt; i++) // 쌍 출력
        cout << pair[i].first << ' ' << pair[i].second << '\n';
    cout << cnt; // 쌍 개수 출력
    return 0;
}