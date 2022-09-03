#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> serial_no;

int computeSum(string s) {
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') continue; // 알파벳 패스
        sum += (s[i] - '0');
    }
    return sum;
}

bool cmp(string &s1, string &s2) {
    // 1번 규칙
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    // 2번 규칙
    int sum1 = computeSum(s1), sum2 = computeSum(s2);
    if(sum1 != sum2) return sum1 < sum2;
    // 3번 규칙
    return s1 < s2;
}

int main() {
    int n;
    cin >> n;

    serial_no.assign(n, "");
    for(int i = 0; i < n; i++) // 시리얼 번호 입력
        cin >> serial_no[i];

    sort(serial_no.begin(), serial_no.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << serial_no[i] << '\n';
    return 0;
}