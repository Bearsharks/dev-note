#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int cur, int last, int sum, vector<int>& v, unordered_map<int, int>& m) {
    if (last == cur) {
        m[sum]++;
        return;
    }
    dfs(cur + 1, last, sum, v, m);
    dfs(cur + 1, last, sum + v[cur], v, m);
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    unordered_map<int, int> m1, m2;
    dfs(0, n / 2, 0, v, m1);
    dfs(n / 2, n, 0, v, m2);
    long long  answer = 0;  

    unordered_map<int, int>* m1p = &m1;
    unordered_map<int, int>* m2p = &m2;
    if (m1.size() > m2.size()) swap(m1p, m2p);
    for (pair<int,int> p : *m1p) {
        answer += (*m2p)[s - p.first] * (long long)p.second;
    }
    if (s == 0) answer--;
    cout << answer;
    return 0;
}