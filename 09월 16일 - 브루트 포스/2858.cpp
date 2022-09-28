#include <iostream>

using namespace std;

typedef pair<int, int> pi;

pi roomSize(int r, int b) { // 상근이 방 크기 구하기
    int total = r + b; // 전체 타일 개수

    for(int w = 1; w <= total; w++) { // (w : 너비)
        if(total % w) continue; // l * w == total을 만족하지 못함
        int l = total / w;
        // 빨간색, 갈색 타일 개수 만족 (테두리를 제외한 안 부분)
        if(b == (l - 2) * (w - 2)) {
            return {l, w};
        }
    }
}

int main() {
    int r, b;
    cin >> r >> b;

    pi ans = roomSize(r, b);
    cout << ans.first << ' ' << ans.second;
    return 0;
}