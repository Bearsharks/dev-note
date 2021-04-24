#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> dp;
	vector<pair<int,int>> v;
	int last = -1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back({ a,0 });
		vector<int>::iterator curlast = lower_bound(dp.begin(),dp.end(), a);
		if (curlast == dp.end()) {
			dp.push_back(a);
			v.back().second = dp.size();
		}
		else{
			*curlast = a;
			v.back().second = curlast - dp.begin()+1;
		}
	}

	cout << dp.size() << "\n";

	vector<int> answer;
	int cur = dp.size();
	for (vector<pair<int,int>>::reverse_iterator iter = v.rbegin(); iter != v.rend(); iter++) {
		if (iter->second == cur) {
			answer.push_back(iter->first);
			cur--;
		}
	}
	for (vector<int>::reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}