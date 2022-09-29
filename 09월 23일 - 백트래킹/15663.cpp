#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
int arr[SIZE]; // 수열

void backtracking(int cnt, int m, int n, vector<int> num, vector<bool> visited) {
    if(cnt == m) { // 길이가 m인 수열 출력
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int pre = 0;
    for(int i = 0; i < n; i++) {
        // 이미 탐색한 수열이거나 이미 사용한 숫자 pass
        if(pre == num[i] || visited[i]) continue;

        arr[cnt] = num[i];
        visited[i] = true; // (i번째 수 사용)
        backtracking(cnt+1, m, n, num, visited);
        visited[i] = false; // (i번째 수 사용 취소)
        pre = num[i];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> num(n, 0);
    vector<bool> visited(n, false); // 방문 여부 저장
    for(int i = 0; i < n; i++) { // n개의 수 입력
        cin >> num[i];
    }
    sort(num.begin(), num.end()); // 오름차순 정렬

    backtracking(0, m, n, num, visited);
    return 0;
}