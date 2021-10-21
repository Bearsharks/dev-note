#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> lr = { 1, 0, 3, 2 };
vector<int> ud = { 2, 3, 0, 1 };

int unFold(int cur, int s, int d) {
	return s + d - (cur - s);
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(1 << n, vector<int>(1 << n));
	pair<int,int> ul = { 0,0 };
	pair<int, int> dr = { (1 << n)-1, (1 << n) - 1 };
	vector<char> fold;
	for (int i = 0; i < 2*n ; i++) {
		char c;
		cin >> c;
		fold.push_back(c);
		if (c == 'R') {
			ul = { ul.first, ((dr.second + ul.second) / 2) + 1 };
		}
		else if (c == 'L') {
			dr = { dr.first, (dr.second + ul.second) / 2};
		}
		else if (c == 'U') {
			dr = { (dr.first + ul.first)/2, dr.second};
		}
		else {
			ul = { ((dr.first + ul.first) / 2) + 1 , ul.second };
		}
	}
	cin >> v[dr.first][dr.second];
	reverse(fold.begin(), fold.end());
	for (char c : fold) {
		if (c == 'R') {
			int s = ul.second;
			for (int i = ul.first; i <= dr.first; i++) {
				for (int j = ul.second; j <= dr.second; j++) {
					v[i][unFold(j,s,-1)] = lr[v[i][j]];
				}
			}
			ul.second = unFold(dr.second, s,-1);
		}
		else if (c == 'L') {
			int s = dr.second;
			for (int i = ul.first; i <= dr.first; i++) {
				for (int j = ul.second; j <= dr.second; j++) {
					v[i][unFold(j, s,1)] = lr[v[i][j]];
				}
			}
			dr.second = unFold(ul.second, s,1);
		}
		else if (c == 'U') {
			int s = dr.first;
			for (int i = ul.first; i <= dr.first; i++) {
				for (int j = ul.second; j <= dr.second; j++) {
					v[unFold(i,s,1)][j] = ud[v[i][j]];
				}
			}
			dr.first = unFold(ul.first, s,1);
		}
		else {
			int s = ul.first;
			for (int i = ul.first; i <= dr.first; i++) {
				for (int j = ul.second; j <= dr.second; j++) {
					v[unFold(i, s,-1)][j] = ud[v[i][j]];
				}
			}
			ul.first = unFold(dr.first, s,-1);
		}
		
	}
	for (int i = ul.first; i < (1 << n); i++) {
		for (int j = ul.second; j < (1 << n); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}