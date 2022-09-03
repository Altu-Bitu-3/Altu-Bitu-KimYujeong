#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b;

int minSum(int n) { // S 최솟값 만들기
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

int main() {
    int n;
    cin >> n;

    a.assign(n, 0);
    b.assign(n, 0);

    for(int i = 0; i < n; i++) // A 입력
        cin >> a[i];

    for(int i = 0; i < n; i++) // B 입력
        cin >> b[i];

    sort(a.begin(), a.end()); // 오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); // 내림차순 정렬

    cout << minSum(n);
    return 0;
}