#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n ;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];		
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += v[j];
			if (sum > 100 * (j - i + 1)) {
				mx = max(j - i + 1, mx);
			}
		}
	}
	
	cout << mx;
	return 0;
}