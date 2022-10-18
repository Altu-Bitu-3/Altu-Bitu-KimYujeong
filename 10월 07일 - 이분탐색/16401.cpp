#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> l; // 과자 길이 저장

int cntNephew(int k, int n) { // 과자 길이가 k일 때 조카 몇 명에게 나누어 줄 수 있는가
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (l[i]/k);
    return cnt;
}

int binarySearch(int left, int right, int m, int n) {
    int answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2; // 막대 과자 최대 길이
        int nephew = cntNephew(mid, n); // 나누어 줄 수 있는 조카 수

        if(nephew >= m) { // 1. 조카 m명에게 분배 가능 -> 길이 늘리기
            answer = mid;
            left = mid + 1;
        }
        else { // 2. 조카 m명에게 분배 불가능 -> 길이 줄이기
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    int m, n;
    cin >> m >> n;

    l.assign(n, 0);
    for(int i = 0; i < n; i++) // 과자 길이 입력
        cin >> l[i];
    sort(l.begin(), l.end()); // 과자 길이 오름차순 정렬

    cout << binarySearch(1, l[n-1], m, n);
    return 0;
}