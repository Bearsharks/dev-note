#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n;
	set<tuple<int,int,int>> remain;
	for (int i = 1; i <= n; i++) {
		int num, money;
		cin >> num >> money;
		remain.insert( make_tuple(num, money, i));
	}
	set<tuple<int, int, int>> test;
	cin >> m;
	set<pair<int,int>> seatset;
	vector<int> ans(m + 1);
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		seatset.insert({ a, i });
	}
	int cnt = 0;
	int money = 0;
	for (pair<int, int> seat : seatset) {
		int num = seat.first;
		while (!remain.empty() && get<0>(*remain.begin()) <= num) {
			tuple<int, int, int> tu = *remain.begin();
			swap(get<0>(tu), get<1>(tu));
			test.insert(tu);
			remain.erase(remain.begin());
		}
		if (!test.empty()) {
			cnt++;
			money += get<0>(*test.rbegin());
			ans[seat.second] = get<2>(*test.rbegin());
			test.erase(--test.end());
		}
		
	}
	cout << cnt << " " <<  money;
	for (int i = 1; i <= m; i++) {
		if (ans[i]) {
			cout << "\n" << ans[i] << " " << i;
		}		
	}
	return 0;
}