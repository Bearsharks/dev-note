#include <iostream>
#include <vector>
using namespace std;

vector<int> genre;
vector<int> v;
int n;
void check(int& i) {
	int j = i;
	for (; j <= n; j++) {
		if (v[i] != v[j + 1]) break;
	}
	if (v[i - 1] == v[j + 1]) genre[v[i]] += 2;
	else genre[v[i]] += 1;
	i = j;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int k;
	cin >> n >> k;
	v.assign(n + 2,0);
	genre.assign(k + 1,0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	
	for (int i = 1; i <= n; i++) {
		check(i);
	}
	int ans = 0;
	int maxstress = 0;
	for (int i = 1; i <= k; i++) {
		if (genre[i] > maxstress) {
			ans = i;
			maxstress = genre[i];
		}
	}
	cout << ans;
	return 0;
}