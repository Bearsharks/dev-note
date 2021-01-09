#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> cs(n + 1);
	vector<vector<int>> v(n+1);
	vector<pair<int,int>> pos(2501);
	for (int i = 1; i <= n; i++) {
		cin >> cs[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		v[i].push_back(0);
		for (int j = 1; j <= cs[i]; j++) {
			int p;
			cin >> p;
			v[i].push_back(p);
			pos[p] = { i,j };
			cnt++;
		}
	}
	int curr = 1;
	int curl = 0;
	
	vector<pair<int,int>> ans;
	for (int i = 1; i <= cnt; i++) {
		if (++curl > cs[curr]) {
			curr++;
			curl = 1;
		}		
		if (curr != pos[i].first || curl != pos[i].second) {
			ans.push_back({ curr,curl });
			ans.push_back(pos[i]);
			int save = v[curr][curl];
			
			pos[v[curr][curl]] = pos[i];
			v[pos[i].first][pos[i].second] = v[curr][curl];
		}
	}
	cout << ans.size() / 2 << "\n";
	for (int i = 0; i < ans.size(); i+=2) {
		cout << ans[i].first << " "<< ans[i].second << " " << ans[i + 1].first << " " << ans[i + 1].second << "\n";
	}
	return 0;
}