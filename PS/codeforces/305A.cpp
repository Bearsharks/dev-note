#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ans;
	int a19 = -1;
	int a1090 = -1;
	int remain = -1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0 || a == 100) {
			ans.push_back(a);
		}
		else if (a % 10 == 0) {
			a1090 = a;
		}
		else if (a < 10) {
			a19 = a;
		}
		else remain = a;
	}
	
	if (a19 == -1 && a1090 == -1 && remain != -1) {
		ans.push_back(remain);
	}
	if (a19 != -1) ans.push_back(a19);
	if (a1090 != -1) ans.push_back(a1090);
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}