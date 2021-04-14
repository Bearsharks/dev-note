#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, vector<pair<int, char>>> m;
	int x = 0;
	int y = 0;

	int i = 1;
	int a, b;
	cin >> a;
	for (int j = 0; j < a; j++, y++) {
		m[y].push_back({++x,'/' });
	}
	y--;
	for (; i < n; i++) {		
		cin >> b;
		for (int j = 0; j < b; j++,y--) {
			m[y].push_back({ ++x,'\\' });
		}
		y++;
		if (++i == n) break;
		cin >> a;
		for (int j = 0; j < a; j++, y++) {
			m[y].push_back({ ++x,'/' });
		}
		y--;		
	}
	int end = m.begin()->first;
	for (map<int, vector<pair<int, char>>>::reverse_iterator i = m.rbegin(); i != m.rend(); i++) {
		int cur = 0;
		
		for (pair<int, char> p : i->second) {
			for (int i = 0,size= p.first - cur - 1; i <size; i++) {
				cout << " ";
			}
			cur = p.first;
			cout << p.second;
		}
		for (int i = 0, size = x - cur; i < size; i++) {
			cout << " ";
		}
		cout << "\n";
	}
	
	return 0;
}