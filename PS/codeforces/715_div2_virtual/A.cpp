#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a & 1) {
				odd.push_back(a);
			}
			else {
				even.push_back(a);
			}
		}
		for(int i : odd){
			cout << i << " ";
		}
		for (int i : even) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}