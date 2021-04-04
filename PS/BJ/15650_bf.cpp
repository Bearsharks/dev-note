#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans(10);
int n, m;
void f(int cur, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m;i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (n - cur+1>= m - cnt) {
		ans[cnt] = cur;
		f(cur + 1, cnt + 1);
		f(cur + 1, cnt);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n>>m;
	f(1, 0);
	return 0;
}