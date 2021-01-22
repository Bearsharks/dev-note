#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector<pair<int, int>> v[2];
int curi[2] = { 0,0 };
map<int,int> m[2];
int findBestMess(int curcandy, int x) {
	while (curi[curcandy] < v[curcandy].size() && v[curcandy][curi[curcandy]].first <= x) {
		m[curcandy][v[curcandy][curi[curcandy]].second]++;
		curi[curcandy]++;
	}
	int result = m[curcandy].rbegin()->first;
	if (--(m[curcandy][result]) == 0) {
		m[curcandy].erase(result);
	}
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	
	while (n--) {
		int k, h, m;
		cin >> k >> h >> m;
		v[k].push_back({h,m});
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	m[0][-1] = 10000;
	m[1][-1] = 10000;

	int curcandy = 0;
	int ans1 = 0;
	int k = x;
	int bm = findBestMess(curcandy, k);
	while (bm != -1) {
		ans1++;
		k += bm;
		curcandy = !curcandy;
		bm = findBestMess(curcandy, k);				
	} 

	m[0].clear();
	m[1].clear();
	m[0][-1] = 10000;
	m[1][-1] = 10000;
	curi[0] = 0;
	curi[1] = 0;
	curcandy = 1;
	int ans2 = 0;
	bm = findBestMess(curcandy, x);
	while (bm != -1) {
		ans2++;
		x += bm;
		curcandy = !curcandy;
		bm = findBestMess(curcandy, x);
	}

	cout << max(ans1,ans2);

	return 0;
}
