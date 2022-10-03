#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> pq;

bool presentGifts(pq c, int m, vector<int> w) {
    for(int i = 0; i < m; i++) {
        int gift = c.top(); c.pop(); // (현재 선물이 가장 많이 담겨있는 상자의 선물 수)
        // 1. 선물을 가져가는 경우
        if(gift >= w[i]) {
            c.push(gift-w[i]); // 원하는 양 가져가기
            continue;
        }
        // 2. 선물을 가져가지 못하는 경우
        return false;
    }
    return true;
}

int main() {
    int n, m, x;
    cin >> n >> m;

    pq c;
    while(n--) { // 선물 상자의 선물 개수 입력
        cin >> x;
        c.push(x);
    }

    vector<int> w(m, 0);
    for(int i = 0; i < m; i++) { // 아이들이 원하는 선물 개수
        cin >> w[i];
    }

    cout << presentGifts(c, m, w);
    return 0;
}