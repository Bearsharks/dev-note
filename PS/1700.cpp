#include <queue>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<queue<int>> t(101);
    vector<int> v;
    set<int> multi;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        t[a].push(i);
        v.push_back(a);
    }
    int answer = 0;
    for (int i = 0; i < k; i++) {
        t[v[i]].pop();
        if(multi.size() < n || multi.count(v[i])) multi.insert(v[i]);
        else {
            answer++;
            int tgt;
            int cnt = -1;
            for (int j : multi) {
                if (t[j].empty() || t[j].front() > cnt) {
                    tgt = j;
                    cnt = t[j].empty() ? 987654321 : t[j].front();
                }
            }
            multi.erase(tgt);
            multi.insert(v[i]);
        }
    }
    cout << answer;
    return 0;
}