#include <iostream>
#include <set>

using namespace std;

void add(int x, set<int> &s) { // add 연산
    s.insert(x);
}

bool check(int x, set<int> &s) { // check 연산
    return s.find(x) != s.end();
}

void remove(int x, set<int> &s) { // remove 연산
    s.erase(x);
}

void toggle(int x, set<int> &s) { // toggle 연산
    if(check(x, s)) remove(x, s);
    else add(x, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, x;
    string cmd;
    set<int> s;
    set<int> all_s; // 1부터 20까지 모든 원소가 들어있는 집합
    for(int i = 1; i <= 20; i++) all_s.insert(i);

    cin >> m;
    while(m--) { // 연산 수행
        cin >> cmd;
        if(cmd == "add") {
            cin >> x;
            add(x, s);
        }
        else if(cmd == "remove") {
            cin >> x;
            remove(x, s);
        }
        else if(cmd == "check") {
            cin >> x;
            cout << check(x, s) << '\n';
        }
        else if(cmd == "toggle") {
            cin >> x;
            toggle(x, s);
        }
        else if(cmd == "all") {
            s = all_s;
        }
        else if(cmd == "empty") {
            s = {};
        }
    }
    return 0;
}