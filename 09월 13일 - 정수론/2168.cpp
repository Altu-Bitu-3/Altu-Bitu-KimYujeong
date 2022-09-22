#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int x, y;
    cin >> x >> y;

    int g = gcd(max(x, y), min(x, y));
    if(g == 1) cout << x + y - 1;
    else cout << (x/g + y/g - 1) * g;
    return 0;
}