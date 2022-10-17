#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int cntClassroom(int n, vector<pi> timetable) { // 강의실 개수 세기
    int idx = 0;
    priority_queue<int, vector<int>, greater<>> classroom; // 강의실 종료시간 저장
    classroom.push(timetable[idx++].second);

    while(idx < n) {
        // classroom.top() : 전 수업의 종료시간
        // timetable[idx].first : 현재 수업의 시작시간

        // 현재 수업의 시작시간이 전 수업의 종료시간 이후인 경우, 강의 이어서 진행
        if(classroom.top() <= timetable[idx].first) classroom.pop();
        classroom.push(timetable[idx++].second); // 강의 종료시간 입력
    }
    return classroom.size();
}

int main() {
    int n;
    cin >> n;

    vector<pi> timetable(n, {0, 0});
    for(int i = 0; i < n; i++) // 수업 시작시간, 종료시간 입력
        cin >> timetable[i].first >> timetable[i].second;
    sort(timetable.begin(), timetable.end()); // 강의 시작시간 오름차순 정렬

    cout << cntClassroom(n, timetable);
    return 0;
}