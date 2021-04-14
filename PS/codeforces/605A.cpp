#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n ;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[a] = i;
	}
	int cnt = 1;
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] > v[i - 1]) cnt++;
		else {
			mx = max(cnt, mx);
			cnt = 1;
		}
	}
	mx = max(cnt, mx);
	cout << n-mx;
	return 0;
}