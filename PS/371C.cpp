#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

vector<pair<ull, ull>> v(3);
vector<ull> cost(3);
ull money(ull mid) {
	ull result = 0;
	for (int i = 0; i < 3; i++) {
		ull need = mid * v[i].second;
		ull cur = v[i].first;
		if (need > cur) result += (need - cur) * cost[i];
	}	
	return result;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	for (char c : str) {
		if (c == 'B')v[0].second++;
		else if (c == 'S')v[1].second++;
		else if (c == 'C')v[2].second++;
	}
	cin >> v[0].first >> v[1].first >> v[2].first;

	cin >> cost[0] >> cost[1] >> cost[2];
	ull k;
	cin >> k;
	ull mx = 1e12+200;
	ull mn = 0;
	while (mx > mn) {
		ull mid = (mx + mn) / 2;
		ull result = money(mid);
		if (result > k ) {
			mx = mid;
		}
		else{
			mn = mid+1;
		}
	}
	cout << mx -1;
	return 0;
}