#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    int s, e;
    cin >> n >> s >> e;
    vector<vector<int>> v(n+1);
    vector<bool> isVisit(n+1);
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int,int>> q;
    q.push({ s,0 });
    isVisit[s] = true;
    int answer = 0;
    while (q.size()) {
        int cur = q.front().first;
        int n = q.front().second;
        q.pop();
        for (int adj : v[cur]) {
            if (!isVisit[adj]) {
                if (adj == e) {
                    cout << n + 1;
                    return 0;
                }
                isVisit[adj] = true;
                q.push({ adj,n + 1 });
            }
        }
    }
    cout << -1;
    return 0;
}