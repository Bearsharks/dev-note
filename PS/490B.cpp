#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(1000001,0);
	unordered_set<int> backs;
	vector<int> fronts;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
		fronts.push_back(a);
		backs.insert(b);
	}
	int first = 0;
	for (int i : fronts) {
		if (backs.count(i) == 0) {
			first = i;
			break;
		}
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i+=2) {
		ans[i] = first;
		first = v[first];
	}
	first = v[0];
	for (int i = 1; i < n; i += 2) {
		ans[i] = first;
		first = v[first];
	}
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}