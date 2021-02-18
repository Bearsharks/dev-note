#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> s(26);
vector<bool> complete(26);
set<int> pathnode;
bool dfs(int cur) {		
	pathnode.insert(cur);
	for (int i : s[cur]) {	
		if (pathnode.count(i)) return false;
		if (!complete[i] && !dfs(i)) {
			return false;
		}		
		for (int j : s[i]) {
			s[cur].insert(j);
		}
	}
	pathnode.erase(cur);
	complete[cur] = true;
	return true;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 1; i < n; i++) {
		int cur = 0;
		while (v[i - 1].size() > cur && v[i].size() > cur && v[i - 1][cur] == v[i][cur]) {
			cur++;
		}
		if (v[i - 1].size() > cur && v[i].size() > cur) {
			int src = v[i - 1][cur] - 'a';
			int dst = v[i][cur] - 'a';
			s[dst].insert(src);
		}
		else if (v[i - 1].size() > v[i].size()) {
			cout << "Impossible";
			return 0;
		}		 
	}
	for (int i = 0; i < 26; i++) {
		if (!complete[i] && !dfs(i)) {
			cout << "Impossible";
			return 0;
		}
	}
	int cnt = 0;
	int i = 0;
	vector<bool> isvisit(26);
	while (cnt < 26) {
		int cur = i++ % 26;
		if (!isvisit[cur] && s[cur].size() == 0) {
			isvisit[cur] = true;
			char c = cur + 'a';
			cout << c;
			cnt++;
			for (int j = 0; j < 26; j++) {
				s[j].erase(cur);
			}
		}
	}
	
	return 0;
}