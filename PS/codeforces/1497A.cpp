#include <iostream>
#include <map>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> v;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v[a]++;
		}
		for (map<int, int>::iterator i = v.begin(); i != v.end(); i++) {
			cout << i->first << " ";
			i->second--;
		}
		for (map<int, int>::iterator i = v.begin(); i != v.end(); i++) {
			for (int j = 0; j < i->second; j++) {
				cout << i->first << " ";
			}
		}
		cout << "\n";
	}
	
	

	return 0;
}