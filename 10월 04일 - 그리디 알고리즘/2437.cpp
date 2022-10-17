#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minWeight(int n, vector<int> weight) {
    // (1, max) : 1부터 max까지 무게 측정 가능
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max+1 < weight[i]) return max+1; // max+1 측정 불가 (== 빈 구간 생김)
        max += weight[i];
    }
    return max+1;
}

int main() {
    int n;
    cin >> n;

    vector<int> weight (n, 0);
    for(int i = 0; i < n; i++) // 추 무게 입력
        cin >> weight[i];
    sort(weight.begin(), weight.end()); // 무게 오름차순 정렬

    cout << minWeight(n, weight);
    return 0;
}