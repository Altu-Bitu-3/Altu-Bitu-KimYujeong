#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> pq;

string magicHammer(int h_centi, int t, pq height) {
    int cnt = 0; // 뿅망치 사용횟수 저장
    while (cnt < t) {
        int tallest = height.top();
        if(h_centi > tallest || tallest == 1) break; // 뿅망치 사용 중단

        height.push(tallest/2);
        height.pop();
        cnt++;
    }

    int tallest_giant = height.top(); // 현재 가장 큰 거인의 키
    if(h_centi > tallest_giant) { // 1. 모든 거인이 센티보다 작은 경우
       return "YES\n" + to_string(cnt);
    }
    else { // 2. 센티보다 큰 거인이 있는 경우
        return ("NO\n" + to_string(tallest_giant));
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

    cout << magicHammer(h_centi, t, height);
    return 0;
}