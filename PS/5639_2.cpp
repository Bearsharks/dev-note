#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f(vector<int>& v, vector<int>::iterator s, vector<int>::iterator e) {
	if (s == e) return;
	int cur = *s;
	vector<int>::iterator ub = upper_bound(s, e, cur);
	s++;
	f(v, s, ub);
	f(v, ub, e);
	cout << cur << "\n";
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v;
	int val;
	while (cin >> val) {
		if (val == EOF) break;
		v.push_back(val);		
	}
	f(v, v.begin(), v.end());
	return 0;
}