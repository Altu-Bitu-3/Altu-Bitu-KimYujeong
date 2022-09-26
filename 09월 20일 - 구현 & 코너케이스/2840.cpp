#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;

// 화살표가 가리키는 위치에 이미 다른 알파벳이 있는가
bool anotherAlphabet(int pointer, char alphabet, vector<char> wheel) {
    if(wheel[pointer] != '?' && wheel[pointer] != alphabet) return true;
    return false;
}

// 해당 알파벳이 현재 알파벳이 가리키는 곳 외에 다른 위치에도 존재하는가
bool duplicate(int pointer, char alphabet, vector<int> pos) {
    if(pos[alphabet-'A'] != -1 && pos[alphabet-'A'] != pointer) return true;
    return false;
}

bool isLucky(int pointer, char alphabet, vector<char> wheel, vector<int> pos) { // 행운의 바퀴인가
    // 1. 화살표가 가리키는 위치에 이미 다른 알파벳이 있는 경우
    if(anotherAlphabet(pointer, alphabet, wheel)) return false;
    // 2. 해당 알파벳이 현재 알파벳이 가리키는 곳 외에 다른 위치에도 존재하는 경우
    if(duplicate(pointer, alphabet, pos)) return false;
    return true;
}

int main() {
    int n, k, s;
    char alphabet;
    cin >> n >> k;

    int pointer = 0; // 화살표가 가리키는 알파벳 위치
    bool lucky = true; // 행운의 바퀴 여부
    vector<int> pos (SIZE, -1); // 알파벳의 위치 (-1 : 바퀴에 해당 알파벳이 존재하지 않음)
    vector<char> wheel (n, '?');
    while(k--) { // k번 회전
        cin >> s >> alphabet;
        pointer = (pointer - (s % n) + n) % n; // 시계방향 회전

        // 행운의 바퀴가 없는 경우
        if(!lucky || !isLucky(pointer, alphabet, wheel, pos)) {
            lucky = false;
            continue;
        }
        wheel[pointer] = alphabet;
        pos[alphabet-'A'] = pointer;
    }

    if(!lucky) { // 행운의 바퀴가 없는 경우
        cout << '!';
        return 0;
    }
    for(int i = 0; i < n; i++) { // 시계방향으로 알파벳 하나씩 출력
        cout << wheel[(pointer + i) % n];
    }
    return 0;
}