#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 1. 무식하게 푼다
// 90000개의 곰팡이를 8회 10000번 체크 8방향 가보고 셋을 왔다 갔다하면서 채워나감
// 마지막 결과에 청소 검사날의 위치가 들어있는지 체크하면됨
// 90000 * 8 * 10000 <- 300이라고 생각해서 1억번정도니까 되겠지했는데 아니었음 100억 번 정도였음
// 2. 잘 살펴봄
// 왔다갔다 함 나이트 같은 움직임으로 왔다 갔다 함.
// 해당 위치에 도착할 때 짝수 앞으로 짝수번째날에 해당위치에 곰팡이가 생길것이고,
// 홀수 일때 도착하면 홀수번째 날에 곰팡이가 생길것, 항상 곰팡이가 있음
// 곰팡이가 새로 생기면, 새로 생긴 곰팡이에서 갈 수 있는 위치에서 
// 그 위치에 짝수번째 도착인지 홀 수 번째 도착인지 체크,
// 짝수 곰팡이랑 홀수곰팡이는 다른 곰팡이로 취급함
// 이걸 최대 t번 하는데, 만약 새로운 곰팡이가 없으면 그만 함. 금방 그만하게 될 것
// 
// 틀림 없어지면 다시는 곰팡이가 안생기는데 이미 짝수에서 방문했다고 되어있어서 포함됨

int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int toMY(int a, int b) {
    return a * 1000 + b;
}
pair<int, int> toInt(int my) {
    return { my / 1000, my - (my / 1000) * 1000 };
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    unordered_set<int> s1;
    unordered_set<int> s2;
    vector<vector<vector<bool>>> v(n, vector<vector<bool>>(n, vector<bool>(2, false)));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s1.insert(toMY( a - 1, b - 1 ));
    }

    for (int i = 1; i <= t; i++) {
        unordered_set<int>& cur = i % 2 == 0 ? s1 : s2;
        unordered_set<int>& prev = i % 2 == 1 ? s1 : s2;
        if (prev.size() == 0) break;
        cur.clear();
        for (int my : prev) {
            pair<int, int> p = toInt(my);
            int r = p.first, c = p.second;
            for (int j = 0; j < 8; j++) {
                int nextr = r + dr[j];
                int nextc = c + dc[j];
                if (0 <= nextr && nextr < n && 0 <= nextc && nextc < n && 
                    v[nextr][nextc][i % 2] == false) { 
                    v[nextr][nextc][i % 2] = true;
                    cur.insert(toMY(nextr, nextc));
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (v[a-1][b-1][t % 2]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}