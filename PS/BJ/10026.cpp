#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };
void bfs(vector<string>& v, vector<vector<int>>& visit, set<char>& s, int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j }); visit[i][j] = 1;
    int n = v.size();
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nexti = p.first + d[k].first;
            int nextj = p.second + d[k].second;
            if (0 <= nexti && nexti < n && 0 <= nextj && nextj < n && !visit[nexti][nextj] && s.count(v[nexti][nextj])) {
                visit[nexti][nextj] = 1;
                q.push({ nexti,nextj });
            }
        }
    }
}

int solution(vector<string>& v, vector<vector<int>>& visit, bool isRG) {
    int n = v.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == 0) {
                ret++;
                set<char> s;
                if (isRG && v[i][j] != 'B') {
                    s.insert('R');
                    s.insert('G');                        
                }
                s.insert(v[i][j]);
                bfs(v, visit, s, i, j);
            }
        }
    }    
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<int>> visit(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solution(v, visit, false) << " ";
    visit.assign(n, vector<int>(n, 0));
    cout << solution(v, visit, true);
    return 0;
}