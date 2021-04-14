#include <iostream>
#include <vector>	
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

pair<ll, ll> x1y1{ 0,0 };
pair<ll, ll> x2y2{ 0,0 };
ll getd(pair<ll, ll> & a, pair<ll, ll>& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
bool test(pair<ll,ll>& a, pair<ll, ll>& b) {
	return getd(x1y1, a) > getd(x1y1, b);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ll n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	x1y1.first = x1;
	x1y1.second = y1;
	x2y2.first = x2;
	x2y2.second = y2;
	ll r1 = 0, r2= 0;
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}
	sort(v.begin(), v.end(), test);
	ll ans = getd(x1y1,v[0]);
	for (int i = 1; i < n; i++) {		
		ll new2 = getd(x2y2, v[i-1]);
		r2 = max(new2, r2);
		ll candi = getd(x1y1, v[i]) + r2;
		ans = min(ans,candi);
	}
	ll new2 = getd(x2y2, v[n-1]);
	ans = min(ans, max(new2, r2));
	cout << ans;
	return 0;
}