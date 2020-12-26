#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(1e6 + 1);
	vector<int> arr(n);
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		v[a]++;
		sum += a;
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		unsigned long long cur = sum - arr[i];

		if (cur & 1 || (cur >> 1) > 1e6) continue;
		v[arr[i]]--;
		if (v[cur >> 1]) ans.push_back(i + 1);
		v[arr[i]]++;
	}

	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;

}
