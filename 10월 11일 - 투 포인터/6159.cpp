#include <iostream>
#include <vector>

using namespace std;

int cntPair(int n, int size, vector<int> cows) { // 서로 다른 쌍 개수 세기
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(cows[i] + cows[j] <= size) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> cows(n, 0);
    for(int i = 0; i < n; i++) { // 소 크기 입력
        cin >> cows[i];
    }

    cout << cntPair(n, s, cows);
    return 0;
}