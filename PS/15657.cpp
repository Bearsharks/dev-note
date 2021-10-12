#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> v;
int mx;
void f(int n, int s) {
	if (mx == nums.size()) {
		for (int num : nums) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s; i < v.size(); i++) {
		nums.push_back(v[i]);
		f(n + 1,i);
		nums.pop_back();		
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
	f(0,0);
	return 0;
}