#include <string>
#include <vector>

using namespace std;

int gap = -1; // 라이언이 몇 점 차를 내면서 이기는가
vector<int> result = {-1};

// 라이언이 몇 점 차이로 이기는지 계산
int computeScore(vector<int> apeach, vector<int> lion) {
    int diff = 0;
    for(int i = 0; i <= 10; i++) {
        int score = 10 - i;
        if(apeach[i] && apeach[i] >= lion[i]) diff -= score; // 어피치 득점
        else if(apeach[i] < lion[i]) diff += score; // 라이언 득점
    }
    return diff;
}

void dfs(int idx, int cnt, int n, vector<int> apeach, vector<int> lion) {
    if(cnt == n || idx == 10) { // 화살 n개 다 쏘았거나 0점 과녁에 도달한 경우, 점수 계산 및 종료
        lion[10] = n - cnt; // 화살이 남은 경우, 다 0점에 할당

        int diff = computeScore(apeach, lion);
        if(diff <= 0) return;

        // 라이언이 우승하는 경우
        if(diff > gap) {
            gap = diff;
            result = lion;
        }
        else if(gap == diff) {
            for(int i = 10; i >= 0; i--) {
                if(lion[i] != result[i]) {
                    result = ((lion[i] > result[i]) ? lion : result);
                    break;
                }
            }
        }
        return;
    }

    // 1. 어피치가 점수를 가져가는 경우
    dfs(idx+1, cnt, n, apeach, lion);

    // 2. 라이언이 점수를 가져가는 경우
    int shot = apeach[idx] + 1; // 라이언이 idx 점수를 가져가기 위해 쏘는 화살 개수
    if(cnt + shot > n) return; // 화살 개수 초과
    lion[idx] = shot;
    dfs(idx+1, cnt+shot, n, apeach, lion);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);
    dfs(0, 0, n, info, lion);
    return result;
}