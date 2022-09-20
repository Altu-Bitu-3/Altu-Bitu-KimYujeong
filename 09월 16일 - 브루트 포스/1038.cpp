#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll; // (가장 큰 수가 9876543210이므로 int 범위 초과함)

void decreasingNum(char digit, string num, vector<ll> &decreasing_num) {
    num += digit;
    decreasing_num.push_back(stoll(num));

    for(char i = '0'; i < digit; i++) {
        decreasingNum(i, num, decreasing_num);
    }
}

int main() {
    int n;
    cin >> n;

    vector<ll> decreasing_num; // 감소하는 수 저장하는 벡터
    for(char i = '0'; i <= '9'; i++) {
        decreasingNum(i, "", decreasing_num);
    }
    sort(decreasing_num.begin(), decreasing_num.end()); // 오름차순 정렬

    cout << ((n >= decreasing_num.size()) ? -1 : decreasing_num[n]); // n번째 감소하는 수 출력
    return 0;
}