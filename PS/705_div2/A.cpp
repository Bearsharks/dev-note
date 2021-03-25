#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a,b;
		cin >> a>> b;
		vector<int> ans;
		for (int i = 1; i <= b/2; i++) {
			ans.push_back(b-i);
		}
		for(int i = b+1; i <= a; i++) ans.push_back(i);
			
		cout << ans.size() << "\n";
		for (int i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}	