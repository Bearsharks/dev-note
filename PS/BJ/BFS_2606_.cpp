#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int answer = 0;
    vector<int> isvisit(n+1);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        // cur에서 갈 수 있는 모든 노드를 순회 v[cur]에 들어있다.
        for (int k : v[cur]) {
            if (isvisit[k] == 0) { // 방문 안 했으면 큐에 넣고 감염 될 것이기에 1더함 
                isvisit[k] = 1;
                q.push(k);
                answer++;
            }
        }
    }

    cout << answer-1;
    return 0;
}