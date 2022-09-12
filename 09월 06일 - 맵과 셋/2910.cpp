#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
map<int, int> order; // key: 숫자, value: 등장 순서

bool cmp(const pi &p1, const pi &p2) { // first: 숫자, second: 해당 숫자의 빈도 수
    // 1. 빈도 수 내림차순
    if(p1.second != p2.second) return p1.second > p2.second;
    // 2. 등장 순서 오름차순
    return order[p1.first] < order[p2.first];
}

int main() {
    int n, c, num;
    cin >> n >> c;

    map<int, int> freq; // key: 숫자, value: 해당 숫자의 빈도 수
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(!freq[num]) order[num] = i; // 처음 나온 수인 경우 등장 순서 넣어주기
        freq[num]++; // 빈도수 증가
    }

    // map 내용을 vector로 옮겨서 정렬
    vector<pi> v(freq.begin(), freq.end()); // first: 숫자, second: 해당 숫자의 빈도 수
    sort(v.begin(), v.end(), cmp);

    for(auto iter = v.begin(); iter != v.end(); iter++) {
        int freq = iter->second; // 해당 숫자 빈도 수
        for(int i = 0; i < freq; i++)
            cout << iter->first << ' ';
    }
    return 0;
}