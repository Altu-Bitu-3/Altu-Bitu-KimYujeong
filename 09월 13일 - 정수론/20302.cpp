#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const int MAX = 1e5;
bool zero = false;
int fact[MAX+1]; // fact[i] = j : i는 j의 배수

void factorization() {
    for(int i = 1; i <= MAX; i++) fact[i] = i;

    for(int i = 2; i <= sqrt(MAX); i++) {
        if(fact[i] != i) continue; // (이미 다른 수의 배수인 경우 pass)
        for(int j = i * i; j <= MAX; j += i) { // (j는 i를 약수로 갖는다)
            if(fact[j] == j) fact[j] = i;
        }
    }
}

void compute(int num, map<int, int> &m, char op) {
    if(num == 0) zero = true; // 0을 곱한 경우
    while(num > 1) {
        switch(op) {
            case '*': m[fact[num]]++; break;
            case '/': m[fact[num]]--; break;
        }
        num /= fact[num];
    }
}

bool isMintChoco(map<int, int> m) { // 민트 초코 여부 반환
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    factorization();

    int n, num;
    char op;
    cin >> n;

    map<int, int> m; // (first : 정수, second : 지수)

    // 첫번째 숫자
    cin >> num;
    compute(num, m, '*');

    while(--n) {
        cin >> op >> num;
        compute(abs(num), m, op);
    }

    if(zero) cout << "mint chocolate"; // 0을 곱한 경우, 무조건 민트 초코
    else cout << (isMintChoco(m) ? "mint chocolate" : "toothpaste");
    return 0;
}