#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> pq;

void magicHammer(int h_centi, int t, pq height) {
    int cnt = 0; // 뿅망치 사용횟수 저장
    while (cnt < t) {
        if(h_centi > height.top() || height.top() == 1) break; // 뿅망치 사용 중단

        height.push(height.top()/2);
        height.pop();
        cnt++;
    }

    int tallest_giant = height.top(); // 현재 가장 큰 거인의 키
    if(h_centi > tallest_giant) { // 1. 모든 거인이 센티보다 작은 경우
        cout << "YES\n" <<  cnt;
    }
    else { // 2. 센티보다 큰 거인이 있는 경우
        cout << "NO\n" << tallest_giant;
    }
}

int main() {
    int n, h_centi, t, h;
    cin >> n >> h_centi >> t;

    pq height;
    while(n--) { // 거인 키 입력
        cin >> h;
        height.push(h);
    }

    magicHammer(h_centi, t, height);
    return 0;
}