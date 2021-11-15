#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, ln;
    cin >> n >> ln;

    vector<vector<int>> graph(200001);
    for (int i = 1; i <= ln; i++) {
        int a;  
        cin >> a;
        while (a != -1) {
            graph[a].push_back(i + 100000);
            graph[i + 100000].push_back(a);
            cin >> a;
        }        
    }
    int s, e;
    cin >> s >> e;
    vector<int> isVisit(200001, -1);

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int stop = q.front(); q.pop();
        for (int adj : graph[stop]) {
            if (isVisit[adj] == -1) {
                isVisit[adj] = adj > 100000 ? isVisit[stop] + 1 : isVisit[stop];
                q.push(adj);
            }
        }
    }
    isVisit[s] = 0;
    cout << isVisit[e];
    return 0;
}