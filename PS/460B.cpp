#include <iostream>
#include <vector>
using namespace std;

int s(long long i) {
	int result = 0;
	while (i > 0) {
		result += i % 10;
		i /= 10;
	}
	return result;
}

long long power(int x, int a) {
	long long result = x;

	while (--a) {
		result *= x;
	}
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a,b,c;
	cin >> a>>b>>c;
	vector<int> ans;
	for (int x = 1; x <= 81; x++) {
		long long candi = b * power(x, a) + c;
		if (candi <= 0 || candi >= 1000000000) {
			continue;
		}
		if (s(candi) == x) {
			ans.push_back(candi);
		}
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}
