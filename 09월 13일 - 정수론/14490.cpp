#include <iostream>

using namespace std;
typedef pair<int, int> pi;

pi stringToInt(string input) { // n:m 형태의 문자열을 정수로 변환하여 n, m 리턴
    string a, b;
    bool split = false;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ':') split = true;
        else if(split) b += input[i];
        else a += input[i];
    }
    return {stoi(a), stoi(b)}; // (문자열 -> 정수 변환)
}

int gcd(int a, int b) { // 최대 공약수 구하기
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    string input, a, b;
    cin >> input;

    pi num = stringToInt(input); // (first : n, second : m)
    int n = num.first, m = num.second;

    // 두 수를 최대한으로 약분 == 두 수를 각각 최대 공약수로 나눈다
    int g = gcd(max(n, m), min(n, m));
    cout << n / g << ':' << m / g << '\n';
    return 0;
}