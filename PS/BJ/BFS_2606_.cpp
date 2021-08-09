#include <iostream>
#include <vector>
#include <set>
#include <tuple>
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
        for (int k : v[cur]) {
            if (isvisit[k] == 0) {
                isvisit[k] = 1;
                q.push(k);
                answer++;
            }
        }
    }
    cout << answer-1;
    return 0;
}