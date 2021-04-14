#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int,int> mp;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a]++;
	}

	for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
		if(iter->second >> 1 > 0) mp[iter->first+1] += iter->second >> 1;
		iter->second = iter->second & 1;
	}
	int prev = -1;
	long long ans = 0;
	for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
		if (iter->second == 0) continue;
		ans += iter->first - prev - 1;
		prev = iter->first;
	}
	cout << ans;

	return 0;
}