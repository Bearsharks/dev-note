#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, d,l;
	cin >> n >> d>> l;
	vector<int> ans;
	if (n & 1) {//oddA
		if (d < 0) {
			if (d < n / 2 * (1 - l) + 1) {
				cout << -1;
				return 0;
			}

			for (int i = 0; i < n / 2; i++) {
				int next = max(d, 1-l);
				ans.push_back(next);
				d -= next;
			}
			if (d == 0) {
				ans.back()--;
				d++;
			}
			ans.push_back(d);
		}
		else {
			if (d > n / 2 * (l - 1) + l) {
				cout << -1;
				return 0;
			}			
			for (int i = 0;  i < n / 2; i++) {
				int next = min(d, l - 1);
				ans.push_back(next);
				d -= next;
			}
			if (d == 0) {
				ans.back()--;
				d++;
			}
			ans.push_back(d);
		}
	}
	else {//even
		if (d < 0) {
			if (d < n / 2 * (1 - l)) {
				cout << -1;
				return 0;
			}
			for (int i = 0; i < n / 2; i++) {
				int next = max(d, 1 - l);
				ans.push_back(next);
				d -= next;
			}
		}
		else {
			if (d > n / 2 * (l - 1)) {
				cout << -1;
				return 0;
			}

			for (int i = 0; i < n / 2; i++) {
				int next = min(d, l - 1);
				ans.push_back(next);
				d -= next;
			}
		}
	}

	for (int i = 0; i < n / 2;i++) {
		if (ans[i] > 0) {
			cout << ans[i]+1 << " 1 ";
		}
		else {
			cout << "1 " << -ans[i] + 1 << " ";
		}
		
	}
	if (n & 1) {
		cout << ans.back();
	}
	return 0;
}