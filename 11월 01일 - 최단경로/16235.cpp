#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

typedef pair<int, int> pi;

struct info {
    int row, col, age;
};

bool cmp (const info &i1, const info &i2) {
    if(i1.age != i2.age) return i1.age < i2.age;
    if(i1.row != i2.row) return i1.row < i2.row;
    return i1.col < i2.col;
}

deque<pi> pos; // (5의 배수인 나무 위치 저장)
deque<info> tree, dead; // (front : 제일 어린 나무, back : 제일 늙은 나무)
vector<vector<int>> a, ground;

void spring() { // 봄
    int cnt = tree.size();
    deque<info> alive;
    while(cnt--) {
        int row = tree.front().row, col = tree.front().col;
        int age = tree.front().age; tree.pop_front();

        // 1. 땅에 양분이 충분한 경우
        if(ground[row][col] >= age) {
            ground[row][col] -= age; // 자신의 나이만큼 양분 먹기
            tree.push_back({row, col, age+1}); // 나이 1 증가
            if((age+1) % 5 == 0) pos.push_back({row, col});
        }
            // 2. 땅에 양분이 부족한 경우
        else {
            dead.push_back({row, col, age});
        }
    }
}

void summer() { // 여름
    while(!dead.empty()) { // 죽은 나무가 양분으로 추가
        int row = dead.back().row, col = dead.back().col;
        int age = dead.back().age; dead.pop_back();
        int amount = age/2;

        if(amount == 0) break; // (back이 제일 늙은 나무를 가리키므로 더아싱 양분 추가할 수 없음)
        ground[row][col] += amount;
    }
    dead.clear();
}

void fall() { // 가을
    while(!pos.empty()) { // 5의 배수인 나무
        int row = pos.back().first, col = pos.back().second;
        pos.pop_back();

        for(int i = 0; i < 8; i++) { // 나무 번식
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row <= 0 || new_row > n || new_col <= 0 || new_col > n) continue;
            tree.push_front({new_row, new_col, 1});
        }
    }
}

void winter() { // 겨울
    for(int i = 1; i <= n; i++) { // 땅에 양분 추가
        for(int j = 1; j <= n; j++) {
            ground[i][j] += a[i][j];
        }
    }
}

int cntTree(int k) {
    ground.assign(n+1, vector<int> (n+1, 5));
    while(k--) {
        spring();
        summer();
        fall();
        winter();
    }
    return tree.size(); // 살아있는 나무의 수 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, k;
    cin >> n >> m >> k;

    a.assign(n+1, vector<int> (n+1, 0));
    for(int i = 1; i <= n; i++) { // a 배열값 입력 (== 양분)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int x, y, z;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        tree.push_back({x, y, z});
    }
    sort(tree.begin(), tree.end(), cmp); // 나이 오름차순 정렬

    cout << cntTree(k);
    return 0;
}