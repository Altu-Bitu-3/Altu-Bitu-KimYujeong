#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 1e6;

vector<int> ngfFuction(int n, vector<int> a, vector<int> freq) {
    vector<int> ngf(n, -1); // 오등큰수 저장하는 배열

    stack<int> s; // (top이 가장 작은 빈도수를 가진 수를 가리킴, 항상 i보다 오른쪽에 위치함)
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty()) {
            if(freq[a[i]] < freq[s.top()]) { // 오등큰수 발견
                ngf[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(a[i]);
    }
    return ngf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> freq (MAX+1,0); // F(Ai) : 등장횟수
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) { // 수열 A 입력
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<int> ngf = ngfFuction(n, a, freq);
    for(int i = 0; i < n; i++)
        cout << ngf[i] << ' ';
    return 0;
}