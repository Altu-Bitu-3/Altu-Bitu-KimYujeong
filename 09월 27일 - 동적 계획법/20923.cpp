#include <iostream>
#include <queue>

using namespace std;

void combine(deque<int> &deq, deque<int> &ground) { // 카드 더미 뒤집어서 합치기
    while(!ground.empty()) {
        deq.push_back(ground.back()); // (가장 아래의 카드를 덱의 가장 아래로)
        ground.pop_back();
    }
}

void win(deque<int> &winner_deq, deque<int> &winner_ground, deque<int> &loser_ground) { // 종을 친 경우
    combine(winner_deq, loser_ground); // 상대방 그라운드 가져오기
    combine(winner_deq, winner_ground); // 내 그라운드 가져오기
}

bool dodoWin(deque<int> ground) { // 도도가 승리하는가
    if(ground.front() == 5) return true;
    return false;
}

bool suyeonWin(deque<int> turn, deque<int> wait) { // 수연이가 승리하는가 (turn: 현재 라운드에 카드를 내려놓은 사람의 그라운드)
    if(!wait.empty() && wait.front() + turn.front() == 5) return true;
    return false;
}

string game(int m, deque<int> dodo, deque<int> suyeon) {
    deque<int> d_ground, s_ground; // 각각 도도와 수연의 그라운드
    int round = 0;
    while(!dodo.empty() && !suyeon.empty()) {
        // 1. 도도가 카드 내려놓기
        d_ground.push_front(dodo.front());
        dodo.pop_front();
        if(dodo.empty()) return "su"; // (덱에 있는 카드가 없어지면 즉시 상대방 승리)

        if(dodoWin(d_ground)) { // 1-1. 도도 득점 check
            win(dodo, d_ground, s_ground);
        }
        else if(suyeonWin(d_ground, s_ground)) { // 1-2. 수연 득점 check
            win(suyeon, s_ground, d_ground);
        }
        if(++round == m) break; // 현재 라운드 종료, m 라운드 진행한 경우 종료

        // 2. 수연이가 카드 내려 놓기
        s_ground.push_front(suyeon.front());
        suyeon.pop_front();
        if(suyeon.empty()) return "do"; // (덱에 있는 카드가 없어지면 즉시 상대방 승리)

        if(dodoWin(s_ground)) { // 2-1. 도도 득점 check
            win(dodo, d_ground, s_ground);
        }
        else if(suyeonWin(s_ground, d_ground)) { // 2-2. 수연 득점 check
            win(suyeon, s_ground, d_ground);
        }
        if(++round == m) break; // 현재 라운드 종료, m 라운드 진행한 경우 종료
    }
    if(dodo.size() > suyeon.size()) return "do"; // 도도가 이기는 경우
    if(dodo.size() < suyeon.size()) return "su"; // 수연이가 이기는 경우
    return "dosu"; // 비긴 경우
}

int main() {
    int n, m, dnum, snum;
    cin >> n >> m;

    deque<int> dodo, suyeon; // 도도와 수연이의 덱 (front: 가장 위, back: 가장 아래)
    while(n--) {
        cin >> dnum >> snum;
        dodo.push_front(dnum);
        suyeon.push_front(snum);
    }

    cout << game(m, dodo, suyeon);
    return 0;
}