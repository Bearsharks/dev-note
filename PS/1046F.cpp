#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	int x, f;	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x >> f;
	
	int maxt = x + f;
	unsigned long long  ans = 0;
	for (int i = 0; i < n; i++){
		int sur = v[i] - x;
		if (sur > 0) {
			ans += ceil( (double)sur / maxt);
		}		
	}
	cout << ans * f;
	return 0;
}