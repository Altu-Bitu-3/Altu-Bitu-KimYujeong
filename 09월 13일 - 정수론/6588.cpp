#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6;
vector<bool> prime; // 소수 여부 저장

void setPrime() { // 소수 여부 세팅
    prime.assign(MAX+1, true);
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 pass
        for(int j = i * i; j <= MAX; j += i) { // (소수 i의 배수는 소수가 아님)
            prime[j] = false;
        }
    }
}

string goldbachConjecture(int n) { // 골드바흐의 추측 결과 반환
    for(int i = 2; i <= n/2; i++) {
        // i와 n-i가 모두 소수인 경우 답 반환 (n == i + n-i)
        if(prime[i] && prime[n-i])
            return (to_string(n) + " = " + to_string(i) + " + " + to_string(n-i));
    }
    return "Goldbach's conjecture is wrong."; // 두 홀수의 합으로 나타낼 수 없는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    setPrime(); // 소수 세팅

    int n;
    while(true) {
        cin >> n;
        if(!n) break; // 테스트 케이스 종료 조건
        cout << goldbachConjecture(n) << '\n';
    }
    return 0;
}