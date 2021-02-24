#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int v, e;
	cin >> v >> e;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (v == 4 || v + 1 > e) {
		cout << -1;
		return 0;
	}
	stringstream ss;
	for (int i = 1; i <= v; i++) {
		if (i != c && i != d && i != a && i != b) {
			ss << " " << i;
		}		
	}
	cout << a << " " << c << ss.str() << " " << d << " " << b<<"\n";
	cout << c << " " << a << ss.str() << " " << b << " " << d;
	return 0;
}