#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >>n;
	priority_queue<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push(-a);
	}
	int ans = 0;
	int cur = 0;
	while (v.size() > 1) {
		cur = 0;
		cur += v.top();
		v.pop();
		cur += v.top();
		v.pop();	
		ans -= cur;
		v.push(cur);
	}
	cout << ans;
	return 0;
}