#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

bool cmp(pi &p1, pi &p2) {
    // 1. y좌표 오름차순
    if(p1.second != p2.second) return p1.second < p2.second;
    // 2. x좌표 오름차순
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;

    vector<pi> cor (n, {0, 0}); // 좌표 정보 저장
    for(int i = 0; i < n; i++)
        cin >> cor[i].first >> cor[i].second;

    sort(cor.begin(), cor.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << cor[i].first << ' ' << cor[i].second << '\n';
    return 0;
}