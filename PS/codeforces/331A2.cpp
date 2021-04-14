#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<long long> v(n+1);
	vector<long long> s(n + 1);
	unordered_map<long long, pair<int,int>> m;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] > 0) sum += v[i];
		s[i] = sum;
		if (m.count(v[i])) m[v[i]].second = i;
		else m[v[i]] = { i,-1 };
	}
	
	long long max = -INT_MAX;
	long long l = 0;
	long long r = 0;
	for (unordered_map<long long, pair<int, int>>::iterator i = m.begin(); i != m.end();i++) {
		if (i->second.second == -1) continue;
		long long candi = 0;
		if (i->first < 0) {
			candi = i->first * 2;
		}
		candi += s[i->second.second] - s[i->second.first-1];
		if (candi > max) {
			max = candi;
			l = i->second.first;
			r = i->second.second;
		}
	}
	
	vector<int> ans;
	for (int i = 1; i < l; i++) {
		ans.push_back( i);
	}
	for (int i = l+1; i < r; i++) {
		if(v[i] < 0) ans.push_back(i); 
	}

	for (int i = r+1; i <= n; i++) {
		ans.push_back(i);
	}

	cout << max << " " << ans.size() << "\n";
	for (int k : ans) {
		cout << k << " ";
	}
	return 0;
}