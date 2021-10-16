#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int INF = 987654321;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (n == m) {
		cout << 0 << "\n" << n;
		return 0;
	}
	vector<pair<int, int>> v(100001, { INF,-1 });
	queue<pair<int,int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int t = q.front().second;
		q.pop();
		int back = cur - 1;
		int forward = cur + 1;
		int tele = 2 * cur;
		if (back == m || forward == m || tele == m) {
			v[m] = { t + 1, cur };
			break;
		}
		if (back >= 0 && v[back].first > t + 1) {
			v[back] = { t + 1, cur };
			q.push({ back,t + 1 });
		}
		if (forward <= 100000 && v[forward].first > t + 1) {
			v[forward] = { t + 1, cur };
			q.push({ forward,t + 1 });
		}
		if (tele <= 100000 && v[tele].first > t + 1) {
			v[tele] = { t + 1, cur };
			q.push({ tele,t + 1 });
		}
	}
	cout << v[m].first << "\n";
	vector<int> answer = { m };
	while (answer.back() != n) {
		answer.push_back(v[answer.back()].second);
	}
	reverse(answer.begin(), answer.end());
	for (int i : answer) {
		cout << i << " ";
	}
	return 0;
}