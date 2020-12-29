#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ull> v(n + 1);
	vector<ull> b(n/2 + 1);
	for (int i = 1; i <= n / 2; i++) {
		cin >> b[i];
	}
	ull i = n / 2;	
	ull prevl = v[i] = b[i] / 2;	
	ull prevr = v[n - i + 1] = b[i] - b[i] / 2;
	for(i--; i > 0; i--) {
		if (b[i] - prevr <= prevl) {
			prevl = v[i] = b[i] - prevr;
			v[n - i + 1] = prevr;
		}
		else {
			v[i] = prevl;
			prevr = v[n - i + 1] = b[i] - prevl;			
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] << " ";
	}
	return 0;

}
