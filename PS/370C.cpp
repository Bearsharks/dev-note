#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> ans;
	//»ö±ò¼ö »ö±ò 
	vector<pair<int,int>> v(m+1);
	//»ö±òº° »ç¶÷
	vector<vector<int>> childs_c(m + 1);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans.push_back({ a, a });
		v[a].first++;
		v[a].second = a;
		childs_c[a].push_back(i);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<int> test;
	for (int i = 0; i < m; i++) {
		for (int j : childs_c[v[i].second]) {
			test.push_back(j);
		}		
	}
	
	for (int i = n / 2, j = 0; i < n; i++,j++) {
		swap(ans[test[i]].second, ans[test[j]].second);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (ans[i].first != ans[i].second);
	}
	cout << cnt;
	for (int i = 0; i < n; i++) {
		cout << "\n" <<  ans[i].first <<  " "<<ans[i].second ;
	}
	return 0;
}