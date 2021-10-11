#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> v;
vector<bool> check(10,false);
int mx;
void f(int n) {
	if (mx == nums.size()) {
		for (int num : nums) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	int prev = -1;
	for (int i = 0; i < v.size(); i++) {
		if (!check[i] && prev != v[i]) {
			check[i] = true;
			nums.push_back(v[i]);
			prev = v[i];
			f(n + 1);
			nums.pop_back();
			check[i] = false;
		}		
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	mx = m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	f(0);
	return 0;
}