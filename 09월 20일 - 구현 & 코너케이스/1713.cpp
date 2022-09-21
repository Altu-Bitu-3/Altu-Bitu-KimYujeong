#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct student{
    int hit, order; // 추천수, 등장순서
}s;

bool cmp(const pair<int, s> &p1, const pair<int, s> &p2) {
    // (p1과 p2의 first는 학생 번호가 들어있음, 정렬 기준에 학생 번호는 불필요함)
    s s1 = p1.second, s2 = p2.second;
    // 1. 추천수 적은 순으로
    if(s1.hit != s2.hit) return s1.hit < s2.hit;
    // 2. 오래된 순으로
    return s1.order < s2.order;
}

map<int, s> finalStudents(int n, int m, vector<int> list) {
    map<int, s> frames; // (key: 학생, value: 추천수, 등장 순서)

    for(int i = 0; i < m; i++) { // 추천 시작
        int student = list[i]; // 추천받은 학생
        // 1. 비어있는 액자가 없는 경우, 기존 학생 삭제
        if(frames.size() == n && frames.find(student) == frames.end()) {
            frames.erase(min_element(frames.begin(), frames.end(), cmp));
        }
        // 2. 추천수 증가, 등장 순서 설정
        if(++frames[student].hit == 1) {
            frames[student].order = i;
        }
    }
    return frames;
}

int main() {
    int n, m; // 사진 틀 수, 학생 추천 횟수
    cin >> n >> m;

    vector<int> list(m, 0);
    for(int i = 0; i < m; i++) // 추천하는 학생 번호 입력
        cin >> list[i];

    map<int, s> frames = finalStudents(n, m, list);
    for(auto iter = frames.begin(); iter != frames.end(); iter++) // 최종 후보 출력
        cout << iter->first << ' ';
    return 0;
}