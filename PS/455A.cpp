#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> v(100001);
	while (n--) {
		int a;
		cin >> a;
		v[a]++;
	}
	long long ans = 0;

	v[2] = v[2] * 2;
	for (long long i = 3 ; i < 100001 ; i++) {
		v[i] *= i;
		v[i] += (v[i - 2] > v[i - 3])? v[i - 2] : v[i - 3];
	}
	cout << max(v[100000], v[99999]);
	return 0;
}
