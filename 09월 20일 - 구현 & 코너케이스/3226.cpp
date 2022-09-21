#include <iostream>

using namespace std;

typedef pair<int, int> pi;

pi endTime(int hh, int mm, int dd) { // 전화가 끝나는 시간
    mm += dd;
    if(mm >= 60) {
        mm -= 60;
        hh += 1;
    }
    if(hh >= 24) hh -= 24;
    return {hh, mm};
}

int computeCost(string start, int dd) { // 전화 요금 계산
    int hh = stoi(start.substr(0, 2));
    int mm = stoi(start.substr(3, 2));

    pi end = endTime(hh, mm, dd);
    if(hh == 6 && end.first == 7) { // 전화 요금이 달라지는 시점 1
        int cost1 = end.second * 10;
        int cost2 = (60 - mm) * 5;
        return cost1 + cost2;
    }
    else if(hh == 18 && end.first == 19) { // 전화 요금이 달라지는 시점 2
        int cost1 = end.second * 5;
        int cost2 = (60 - mm) * 10;
        return cost1 + cost2;
    }
    else if(end.first < 7 || end.first >= 19) return dd * 5;
    else return dd * 10;
}

int main() {
    int n, cost = 0;
    cin >> n;

    string hhmm;
    int dd;
    while(n--) {
        cin >> hhmm >> dd;
        cost += computeCost(hhmm, dd);
    }
    cout << cost;
    return 0;
}