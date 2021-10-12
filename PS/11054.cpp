#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> k;
	vector<int> lengths(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		vector<int>::iterator iter = lower_bound(k.begin(), k.end(), v[i]);
		if (iter == k.end()) {
			lengths[i] = k.size();
			k.push_back(v[i]);
		}
		else {
			*iter = v[i];
			lengths[i] = iter-k.begin();
		}
	}
	k.clear();
	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		vector<int>::iterator iter = lower_bound(k.begin(), k.end(), v[i]);
		if (iter == k.end()) {
			answer = max(answer, lengths[i] + 1 + (int)k.size());
			k.push_back(v[i]);
		}
		else {
			*iter = v[i];
			answer = max(answer, lengths[i] + 1 + (int)(iter - k.begin()));
		}
	}
	cout << answer;
	return 0;
}