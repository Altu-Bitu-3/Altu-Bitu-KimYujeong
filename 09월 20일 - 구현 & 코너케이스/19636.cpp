#include <iostream>
#include <cmath>

using namespace std;

// 1. 일일 기초 대사량 변화를 고려하지 않았을 때
void fixedBasalMetabolicRate(int w, int l0, int d, int l, int a) {
    while(d--) {
        w += (l - (a + l0)); // 일일 에너지 섭취량 - (다이어트 전 일일 기초 대사량 + 일일 활동 대사량)
        if(w <= 0 || l0 <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    cout << w << ' ' << l0 << '\n';
}

// 2. 일일 기초 대사량 변화를 고려했을 때
void BasalMetabolicRateChange(int w, int l0, int t, int d, int l, int a){
    int basal_rate = l0;
    while(d--) {
        int tmp = (l - (a + basal_rate)); // 일일 에너지 섭취량 - (다이어트 전 일일 기초 대사량 + 일일 활동 대사량)
        w += tmp; // 체중 변화
        basal_rate += (abs(tmp) > t ? floor((double) tmp / 2) : 0); // 기초 대사량 변화
        if(w <= 0 || basal_rate <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    bool yoyo = (l0 - basal_rate > 0); // 요요가 일어날 것인가
    cout << w << ' ' << basal_rate << ' ';
    if(yoyo) cout << "YOYO";
    else cout << "NO";
}

int main() {
    int w, l0, t, d, l, a;
    cin >> w >> l0 >> t; // 다이어트 전 체중, 일일 기초 대사량, 기초 대사량 변화 역치
    cin >> d >> l >> a; // 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량

    fixedBasalMetabolicRate(w, l0, d, l, a);
    BasalMetabolicRateChange(w, l0, t, d, l, a);
    return 0;
}