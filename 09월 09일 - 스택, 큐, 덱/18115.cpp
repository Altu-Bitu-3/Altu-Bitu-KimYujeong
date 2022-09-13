#include <iostream>
#include <vector>
#include <queue>

using namespace std;

deque<int> initialCard(int n, vector<int> a) {
    // front: 제일 위의 카드 (가장 먼저 내려놓는 카드)
    // back : 제일 아래의 카드 (가장 나중에 내려놓는 카드)
    deque<int> hand;

    int card = 1; // 카드 번호
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 1) hand.push_front(card++); // 제일 위의 카드로 push
        else if(a[i] == 2) {
            int top = hand.front(); hand.pop_front();
            hand.push_front(card++); // 두번째 카드 먼저 push
            hand.push_front(top); // 제일 위의 카드 다시 push
        }
        else if(a[i] == 3) hand.push_back(card++); // 제일 아래의 카드로 push
    }
    return hand;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) // 수열 A 입력
        cin >> a[i];

    deque<int> hand = initialCard(n, a);
    while(!hand.empty()) {
        cout << hand.front() << ' ';
        hand.pop_front();
    }
    return 0;
}