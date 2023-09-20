#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> v(n);
    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++) {
        // 기울기로 해당 위치에서 최소 값을 계산
        // 그 값보다 같거나 크면 볼 수 있음
        long long pdx = 1;
        long long pdy = -10000000000;
        for (int j = i + 1; j < n; j++) {
            long long dx = j - i;
            long long dy = v[j] - v[i];
            if (dx * pdy < dy * pdx) {
                cnt[j]++;
                cnt[i]++;
                pdx = dx;
                pdy = dy;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, cnt[i]);
    }

    cout << answer;
    return 0;
}