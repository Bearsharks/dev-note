#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(2*n-1);	
	int negecnt = 0;
	int sum = 0;
	for (int i = 0; i < 2 * n - 1;i++) {
		cin >> v[i];
		if (v[i] < 0) {
			sum -= v[i];
			negecnt++;
		}
		else sum += v[i];
	}
	sort(v.begin(), v.end());
	if (!(n & 1) && (negecnt & 1)) {
		if (negecnt == 2 * n - 1) sum += 2 * v.back();
		else sum = max(sum - 2 * v[negecnt], sum + 2 * v[negecnt-1]);
	}
	cout << sum;
	return 0;
}