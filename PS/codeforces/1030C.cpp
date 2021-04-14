#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	int sum = 0;
	for (char c : s) {
		int a = c - '0';
		sum += a;
		v.push_back(a);
	}
	bool isOk = false;
	for (int i = 2; i <= n && !isOk; i++) {
		if (sum % i == 0) {
			int m = sum / i;
			int segment = 0;
			for (int k = 0; k < n; k++) {
				segment += v[k];
				if (segment > m) break;
				else if (segment == m) {
					segment = 0;
					while (k + 1 < n && v[k+1] == 0) {
						k++;
					}
					if (k == n - 1) {
						isOk = true;
					}
				}
			}
		}
	}
	if (isOk) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	

	return 0;
}