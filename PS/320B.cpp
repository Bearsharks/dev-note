#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> node;
vector<int> visit;

bool cango(int x, int y) {
    visit[x] = 1;
    bool result = false;
    for (int next : graph[x]) {
        if (next == y) {
            result = true;
            break;
        }
    }
    if (!result) {
        for (int next : graph[x]) {
            if (!visit[next] && cango(next,y)) {
                result = true;
                break;
            }
        }
    }
    return result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    while (n--) {
        int oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 1) {
            pair<int, int> newnode = { a,b };
            graph.push_back(vector<int>());
            for (int i = 0,size = node.size(); i < size; i++) {
                if ((node[i].first < a && a < node[i].second) || (node[i].first < b && b < node[i].second)) {
                    graph.back().push_back(i);                    
                }
                if ((a < node[i].first && node[i].first < b) || (a < node[i].second && node[i].second < b)) {
                    graph[i].push_back(size);
                }
            }
            node.push_back({ a,b });
        }
        else {
            visit.assign(node.size(),0);
            if (cango(a-1, b-1)) {
                cout << "YES\n";
            }
            else {                
                cout << "NO\n";
            }
        }
    }
    return 0;
}