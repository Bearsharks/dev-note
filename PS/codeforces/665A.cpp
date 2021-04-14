#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, at, b, bt;
	string t;
	cin >> a >> at>> b>> bt >> t;
	int start = ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
	pair<int, int> time = { start, start + at };
	int first = 5 * 60;
	int last = 24 * 60;
	int cur = first;
	vector<pair<int,int>> barrivetimes;
	while (cur < last) {
		barrivetimes.push_back({ cur, cur + bt });
		cur += b;
	}
	int ans = 0;
	for (pair<int, int> btime : barrivetimes) {
		if (time.first < btime.second && time.second > btime.first) ans++;
	}
	cout << ans;
	return 0;
}