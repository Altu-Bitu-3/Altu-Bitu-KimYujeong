#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int MAX = 1e6;

vector<bool> setPrime() { // 소수 세팅
    vector<bool> prime (MAX+1, true);
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(!prime[i]) continue; // (소수 아닌 경우 pass)
        for(int j = i * i; j <= MAX; j += i) { // (소수 i의 배수는 소수가 아님)
            prime[j] = false;
        }
    }
    return prime;
}

int squareSum(string num) { // 각 자리수의 제곱의 합
    int sum = 0; // 각 자리수의 제곱의 합
    for(int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        sum += (digit * digit);
    }
    return sum;
}

bool makeOne(int n) { // 상근수 여부 반환
    set<int> visited;

    while(n != 1) {
        // 무한 루프 방지 (이미 n으로 1을 만들 수 없었음)
        if(visited.find(n) != visited.end()) return false;
        visited.insert(n); // n으로 1 만들기 시도
        n = squareSum(to_string(n));
    }
    return true;
}

vector<int> findNum(int n, vector<bool> prime) { // 소수이면서 상근수인 수 찾기
    vector<int> result;
    for(int i = 2; i <= n; i++) {
        if(prime[i] && makeOne(i)) {
            result.push_back(i); // 소수 상근수 찾음
        }
    }
    return result;
}

int main() {
    vector<bool> prime = setPrime(); // 소수 세팅

    int n;
    cin >> n;

    vector<int> result = findNum(n, prime); // n보다 작거나 같은 소수 상근수
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}