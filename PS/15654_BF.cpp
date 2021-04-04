#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
vector<int> nums;
int n, k;
void f(int cur) {
	if (ans.size() == k) {
		for (int i : ans) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cur; i <= n;i++) {
		ans.push_back(i);
		f(i);
		ans.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	f(1);
	return 0;
}


