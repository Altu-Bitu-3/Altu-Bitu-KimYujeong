#include <iostream>
#include <vector>

using namespace std;

vector<int> pos; // 가로등 위치 저장

bool light(int k, int n, int m) { // 가로등 높이가 k일 때 (0, n)까지 비출 수 있는가
    if(pos[0]-k > 0 || pos[m-1]+k < n) return false; // 커버 불가
    for(int i = 1; i < m; i++) {
        if(pos[i-1]+k < pos[i]-k) { // 중간에 공백이 생기는 경우
            return false;
        }
    }
    return true;
}

int binarySearch(int left, int right, int n, int m) {
    int answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2; // 가로등 높이
        bool cover = light(mid, n, m); // (0, n)까지 비출 수 있는가

        if(cover) { // 1. 커버 가능 -> 가로등 높이 줄이기
            answer = mid;
            right = mid - 1;
        }
        else { // 2. 커버 불가 -> 가로등 높이 늘리기
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    pos.assign(m, 0);
    for(int i = 0; i < m; i++) // 가로등 위치
        cin >> pos[i];

    cout << binarySearch(1, n, n, m);
    return 0;
}