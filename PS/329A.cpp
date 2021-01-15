#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	string es;
	for (int i = 0; i < n; i++) {
		es.push_back('E');
	}
	bool isesexist = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == es) {
			isesexist = true;
			break;
		}
	}
	vector<pair<int, int>> ans;
	if (isesexist) {
		for (int i = 0; i < n; i++) {
			bool find = false;
			for (int j = 0; j < n; j++) {
				if (v[j][i] == '.') {
					find = true;
					ans.push_back({ j,i });
					break;
				}
			}
			if (!find) {
				cout << -1;
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == '.') {
					ans.push_back({ i,j });
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	}
	return 0;

}
