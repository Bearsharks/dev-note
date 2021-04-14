#include <iostream>
#include <vector>
using namespace std;

vector<int> team;
vector<int> isVisit;
vector<vector<int>> v;
bool dfs(int cur) {
    isVisit[cur] = 1;
    team.push_back(cur);
    for (int c : v[cur]) {
        if (!isVisit[c] && (team.size() >= 3 || !dfs(c))) return false;
    }
    return true;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    isVisit.resize(n+1);
    v.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<vector<int>> ans;
    vector<int> solo;
    vector<int> duoteam;
    for (int i = 1; i <= n; i++) {
        if (!isVisit[i]) {
            if (!dfs(i)) {
                cout << -1;
                return 0;
            }
            if (team.size() == 1) {
                solo.push_back(team[0]);                      
            }
            else {
                ans.push_back(team);
                if (team.size() == 2) {
                    duoteam.push_back(ans.size() - 1);
                }
            }
            team.clear();
        }
    }

    bool result = false;
    if (duoteam.size() <= solo.size()) {            
        for (int i = 0; i < duoteam.size(); i++) {
            ans[duoteam[i]].push_back(solo.back());
            solo.pop_back();
        }
        if (solo.size() % 3 == 0) {
            for (int i = 0; i < solo.size(); i += 3) {
                cout << solo[i] << " " << solo[i + 1] << " " << solo[i + 2] << "\n";
            }
            solo.clear();
            result = true;
        }
    }

    if (result) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
        }
    }
    else {
        cout << -1;
        return 0;
    }
    return 0;
}