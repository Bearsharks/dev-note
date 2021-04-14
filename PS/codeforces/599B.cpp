#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> f(100001);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		f[a].push_back(i);
	}
	vector<int> ans;
	bool isambi = false;
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		if (f[a].size() == 1) {
			ans.push_back(f[a][0]);
		}
		else if (f[a].size() == 0) {
			cout << "Impossible";
			return 0;
		}
		else {
			isambi = true;
		}
	}
	if (isambi) {
		cout << "Ambiguity";
		return 0;
	}
	cout << "Possible\n";
	for(int i : ans){
		cout << i << " ";
	}
	return 0;
}