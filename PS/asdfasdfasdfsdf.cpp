#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void sp(vector<vector<int>>& adj) {
    int n = adj.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 987654321;
    vector<vector<int>> adj(n + 1, vector<int>(n+1,987654321));
    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }
    for (int i = 0; i < fares.size(); i++) {
        int here = fares[i][0];
        int there = fares[i][1];
        int cost = fares[i][2];
        adj[here][there] = cost;
        adj[there][here] = cost;
    }
    sp(adj);
    for (int i = 1; i <= n; i++) {
        long long cur = (long long)adj[s][i] + adj[i][a] + adj[i][b];
        if (cur > 987654321) continue;
        answer = min((int)cur, answer);
    }
    return answer;

}

int main() {
    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
    solution(7, 4, 3, 2, fares); 
    return 0;
}