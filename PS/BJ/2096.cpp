#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n ;
	int mx1 = 0, mx2 = 0, mx3 = 0;
	cin >> mx1 >> mx2 >> mx3;
	
	int mn1 = mx1, mn2 = mx2, mn3 = mx3;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int l = max(mx1, mx2);
		int center = max(l, mx3);
		int r = max(mx2, mx3);
		mx1 = a + l;
		mx2 = b + center;
		mx3 = c + r;

		l = min(mn1, mn2);
		center = min(l, mn3);
		r = min(mn2, mn3);
		mn1 = a + l;
		mn2 = b + center;
		mn3 = c + r;
	}
	cout << max(mx1,max(mx2,mx3)) << " " << min(mn1, min(mn2, mn3));
	return 0;
}