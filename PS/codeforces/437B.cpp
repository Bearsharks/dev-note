#include <iostream>
#include <vector>
using namespace std;

int lowbit(int i) {
	int lowdigit = 1;
	while ((i & 1) == 0) {
		i = i >> 1;
		lowdigit++;
	}
	return 1 << (lowdigit -1);
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int sum, limit;
	cin >> sum>> limit;
	vector<int> ans;
	while (sum != 0 && limit != 0) {
		int lb = lowbit(limit);
		if (lb <= sum) {
			sum -= lb;
			ans.push_back(limit);
		}
		limit--;
	}
	if (sum == 0) {
		cout << ans.size() << "\n";
		for (int i : ans) {
			cout << i << " ";
		}		
	}
	else {
		cout << -1;
	}
	return 0;
}
