#include <iostream>
#include <vector>
using namespace std;

int mx = 4001;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n << "\n" << "1 " << n << " " << mx << "\n";

	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		cout << "2 " << i << " " << a + mx - i << "\n";
	}
	
	return 0;

}
