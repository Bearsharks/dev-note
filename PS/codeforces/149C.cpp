#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	vector<int> p,q;
	for (int i = 0; i < n; i++) {

		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(v.begin(), v.end());
	int i = 0;
	int team[2] = { 0,0 };
	vector<vector<int>> pq(2);
	for (; i < n-1; i+=2) {
		bool is0S = team[0] > team[1];//true면 0팀 강하고 그래서 1로 더 큰게 들어감
		team[!is0S] += v[i].first;
		pq[!is0S].push_back(v[i].second);
		team[is0S] += v[i + 1].first;
		pq[is0S].push_back(v[i+1].second);
	}
	if (n & 1) {
		pq[team[0] > team[1]].push_back(v[i].second);
	}
	cout << pq[0].size() << "\n";
	for (int i : pq[0]) {
		cout << i << " ";
	}
	cout << "\n" << pq[1].size() << "\n";
	for (int i : pq[1]) {
		cout << i << " ";
	}
	return 0;
}