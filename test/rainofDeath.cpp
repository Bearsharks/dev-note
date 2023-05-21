#include <vector>
#include <iostream>
using namespace std;

pair<int, int> spos, epos;
vector<pair<int, int>> umbs;
vector<bool> isVisit;
int n, H, D;
int MX = 987654321;
int result = MX;

void f(int i, int j, int h, int d, int cnt) {
    // 해당 위치에서 끝점 방문 가능하면 최소여부 비교 후 갱신
    int distToEnd = abs(epos.first - i) + abs(epos.second - j);
    if (cnt + distToEnd >= result) return;
    if (h + d > distToEnd - 1) {
        result = result < cnt + distToEnd ? result : cnt + distToEnd;
        return;
    }

    // 우산만 방문하면 된다.
    for (int k = 0; k < umbs.size(); k++) {
        if (isVisit[k]) continue;
        int nexti = umbs[k].first;
        int nextj = umbs[k].second;
        int dist = abs(nexti - i) + abs(nextj - j);
        // 지금 가지고 있는 우산은 방문 직전 까지만 쓴다.
        int remain = d < dist ? h - (dist - d - 1) : h;
        if (remain > 0 && cnt + dist < result) {
            // 방문하면 우산 용량 하나 까야함 새거로 막기 때문
            isVisit[k] = true;
            f(nexti, nextj, remain, D - 1, cnt + dist);
            isVisit[k] = false;
        }
    }
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> H >> D;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            if (a == 'S') {
                spos = { i,j };
            }
            else if (a == 'E') {
                epos = { i,j };
            }
            else if (a == 'U') {
                umbs.push_back({ i, j });
            }
        }
    }
    isVisit.assign(umbs.size(), false);
    f(spos.first, spos.second, H, 0, 0);

    cout << (result >= MX ? -1 : result);
    return 0;
}