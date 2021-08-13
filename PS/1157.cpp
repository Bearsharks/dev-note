#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	map<char, int> m;
	string str;
	cin >> str;
	for (char c : str) {
		if (c >= 'a') c += 'A' - 'a';
		m[c]++;
	}
	if (m.size() == 1) cout << m.begin()->first;
	else {
		vector<pair<int, char>> v;
		for (pair<char, int> p : m) {
			v.push_back({ p.second, p.first });
		}
		sort(v.begin(), v.end());
		pair<int, char> one = v.back(); v.pop_back();
		pair<int, char> two = v.back();
		if (one.first == two.first) cout << "?";
		else cout << one.second;

	}

	return 0;
}