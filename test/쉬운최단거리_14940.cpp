#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
pair<int, int> p[] = { {-1,0}, {0,1}, {1,0}, {0, -1} };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                x = i;
                y = j;
                v[i][j] = 0;
            }
            else if (v[i][j] == 1) {
                v[i][j] = 987654321;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({ x,y, 0 });
    while (!q.empty()) {
        tuple<int, int, int> t = q.front(); q.pop();
        // 튜플은 이렇게 값 조회함
        int curi = get<0>(t);
        int curj = get<1>(t);
        int cnt = get<2>(t);
        int k = 4;
        while (--k >= 0) {
            int nexti = curi + p[k].first;
            int nextj = curj + p[k].second;
            // 현재탐색중 curi curj까지의 거리 cnt+1 / v[nexti][nextj] 이전까지 최소 값
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && v[nexti][nextj] > cnt + 1) {
                // 더 작은 것을 선택
                v[nexti][nextj] = cnt + 1;
                q.push({ nexti, nextj, cnt + 1 });
            }
        }
    }

    // 초기 값이 그대로면 도달 할 수 없는 곳 -1로 표시
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 987654321) {
                v[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i][0];
        for (int j = 1; j < m; j++) {
            cout << " " << v[i][j];
        }
        if (i != n - 1) cout << "\n";
    }

    return 0;
}