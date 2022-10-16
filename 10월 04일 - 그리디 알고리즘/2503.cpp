#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct info {
    string num; // 민혁이가 영수에게 물어본 수
    int strike, ball; // 영수의 대답
};

int game(int n, vector<info> ans) { // 가능성이 있는 수 개수 세기
    int cnt = 0; // 가능한 수 개수
    for(int i = 123; i <= 987; i++) {
        string num = to_string(i);
        if(num.find('0') != string::npos) continue; // 0이 존재하는 경우 pass
        if(num[0] == num[1] || num[1] == num[2] || num[0] == num[2]) continue; // 서로 다른 세 숫자로 구성되지 않은 경우 pass

        bool find = true;
        for(int j = 0; j < n; j++) { // 영수의 대답을 만족하는가
            int strike = (num[0] == ans[j].num[0]) + (num[1] == ans[j].num[1]) + (num[2] == ans[j].num[2]);
            if(strike != ans[j].strike) { // i가 영수의 대답을 만족하지 못함
                find = false;
                break;
            }
            int ball = (ans[j].num.find(num[0]) != string::npos) + (ans[j].num.find(num[1]) != string::npos) + (ans[j].num.find(num[2]) != string::npos) - strike;
            if(ball != ans[j].ball) { // i가 영수의 대답을 만족하지 못함
                find = false;
                break;
            }
        }
        if(find) cnt++; // i가 영수의 대답의 strike와 ball 수를 만족함
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    vector<info> ans(n, {"", 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> ans[i].num >> ans[i].strike >> ans[i].ball;
    }
    
    cout << game(n, ans);
    return 0;
}