#include <iostream>

using namespace std;

int computeCost(string start, int dd) { // 전화 요금 계산
    int hh = stoi(start.substr(0, 2));
    int mm = stoi(start.substr(3, 2));

    // 전화 끝나는 시간
    int end_mm = mm + dd;
    int end_hh = hh + (end_mm/60);
    end_mm %= 60; end_hh %= 24;

    if(hh == 6 && end_hh == 7) { // 전화 요금이 달라지는 시점 1
        int cost1 = end_mm * 10;
        int cost2 = (60 - mm) * 5;
        return cost1 + cost2;
    }
    if(hh == 18 && end_hh == 19) { // 전화 요금이 달라지는 시점 2
        int cost1 = end_mm * 5;
        int cost2 = (60 - mm) * 10;
        return cost1 + cost2;
    }
    if(end_hh < 7 || end_hh >= 19) return dd * 5;
    return dd * 10;
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