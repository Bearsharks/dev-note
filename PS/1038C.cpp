#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int doAturn(vector<int>& a, vector<int>& b) {
	int result = 0;
	if (a.empty() || !b.empty() && a.back() < b.back()) {
		b.pop_back();
	}else {
		result = a.back();
		a.pop_back();
	}
	return result;
}

int doBturn(vector<int>& a, vector<int>& b) {
	int result = 0;
	if (b.empty() || !a.empty() && b.back() < a.back()) {
		a.pop_back();
	}else {
		result = b.back();
		b.pop_back();
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	while (!a.empty() || !b.empty()) {
		ans += doAturn(a, b);
		if (!a.empty() || !b.empty()) {
			ans -= doBturn(a, b);
		}
	}


	cout << ans;
	return 0;
}