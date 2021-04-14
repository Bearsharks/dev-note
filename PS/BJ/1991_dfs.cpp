#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph(128);
void dfspre(int cur) {
    cout << (char)cur;
    if (graph[cur].first != '.') dfspre(graph[cur].first);    
    if (graph[cur].second != '.') dfspre(graph[cur].second);
}

void dfsin(int cur) {
    if(graph[cur].first != '.') dfsin(graph[cur].first);
    cout << (char)cur;
    if(graph[cur].second != '.') dfsin(graph[cur].second);
}

void dfspost(int cur) {
    if (graph[cur].first != '.') dfspost(graph[cur].first);
    if (graph[cur].second != '.') dfspost(graph[cur].second);
    cout << (char)cur;    
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 'A'; i < 'A' + n; i++) {
        char q, w, e;
        cin >> q >> w >> e;
        graph[q].first = w;
        graph[q].second = e;
    }
    dfspre('A');
    cout << "\n";
    dfsin('A');
    cout << "\n";
    dfspost('A');
    return 0;
}
