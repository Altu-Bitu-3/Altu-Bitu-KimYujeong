#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6;

vector<bool> setPrime() { // 소수 여부 세팅
    vector<bool> prime (MAX+1, true);
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 pass
        for(int j = i * i; j <= MAX; j += i) { // (소수 i의 배수는 소수가 아님)
            prime[j] = false;
        }
    }
    return prime;
}

string goldbachConjecture(int n, vector<bool> prime) { // 골드바흐의 추측 결과 반환
    if(prime[2] && prime[n-2]) return (to_string(n) + " = " + to_string(2) + " + " + to_string(n-2));

    for(int i = 3; i <= n/2; i += 2) {
        // i와 n-i가 모두 소수인 경우 답 반환 (n == i + n-i)
        if(prime[i] && prime[n-i])
            return (to_string(n) + " = " + to_string(i) + " + " + to_string(n-i));
    }
    return "Goldbach's conjecture is wrong."; // 두 소수의 합으로 나타낼 수 없는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<bool> prime = setPrime(); // 소수 세팅

    int n;
    while(true) {
        cin >> n;
        if(!n) break; // 테스트 케이스 종료 조건
        cout << goldbachConjecture(n, prime) << '\n';
    }
    return 0;
}