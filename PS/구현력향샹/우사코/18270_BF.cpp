#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool test(vector<string>& v, vector<pair<string, string>>& constrains) {
	int cnt = 0;
	for (pair<string, string> p : constrains) {
		for (int i = 1; i < 8; i++) {
			if ((v[i - 1] == p.first && v[i] == p.second)
				|| (v[i] == p.first && v[i - 1] == p.second)) {
				cnt++;
				break;
			}
		}
	}
	return cnt == constrains.size();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> v = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
	sort(v.begin(), v.end());
	int n; 
	cin >> n;
	vector<pair<string,string>> constrains(n);
	for (int i = 0; i < n; i++) {
		string first,second;
		cin >> first;
		for (int j = 0; j < 5; j++) {
			cin >> second;
		}
		constrains[i] = { first,second };
	}
	
	bool result = false;
	do {
		result = test(v, constrains);
		if (result) {
			for (string s : v) 
				cout << s << "\n";
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
