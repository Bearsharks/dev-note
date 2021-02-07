#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long x, y, m;
	cin >>x>>y>>m;
	if ( x >= m || y >= m){
		cout << 0;
		return 0;
	}		
	if( x <= 0 && y <= 0) {
		cout << -1;
		return 0;
	}
	if (x > y) swap(x, y);
	long long ans = 0;
	if (x < 0) {
		ans = (long long)ceil((double)-x / y);
		x += ans * y;
	}
	if (x > y) swap(x, y);
	if (y >= m) {
		cout << ans;
		return 0;
	}
	vector<long long> v = { x, y,x+y };
	while (*v.rbegin() < m) {
		v.push_back(*v.rbegin() + *(v.rbegin()+1));
	}
	ans += v.size() - 2;
	cout << ans;
	return 0;
}