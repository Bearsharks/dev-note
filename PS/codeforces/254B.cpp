#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 0;
	cin >> n;

	//100 121231 101 130101
	int day[13] = { 0,100,};
	day[2] = day[1] + 31, day[3] = day[2] + 28, day[4] = day[3] + 31, day[5] = day[4] + 30;
	day[6] = day[5] + 31, day[7] = day[6] + 30, day[8] = day[7] + 31, day[9] = day[8] + 31;
	day[10] = day[9] + 30, day[11] = day[10] + 31, day[12] = day[11] + 30;
	vector<int> v(500);
	
	int mx = -1;
	while (n--) {
		int m, d, p, t;
		cin >> m >> d >> p >> t;
		d += day[m];
		for (int i = 1; i <= t; i++) {
			v[d - i] += p;
			mx = max(v[d - i], mx);
		}
	}
	cout << mx;
	return 0;
}
