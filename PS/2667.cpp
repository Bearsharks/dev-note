#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int INF = 987654321;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void print(vector<vector<int>>& v) {
	cout << "\n";
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}
	
}
int dfs(int i, int j, vector<vector<int>>& v) {
	int ret = 1;
	int n = v.size();
	v[i][j] = 0;
	for (int k = 0;k < 4; k++) {
		int nextr = i + dr[k];
		int nextc = j + dc[k];
		if (0 <= nextr && nextr < n && 0 <= nextc && nextc < n && v[nextr][nextc]) {
			ret += dfs(nextr, nextc, v);
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {			
			v[i][j] = s[j] - 48;
		}
	}

	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j]) {
				answer.push_back(dfs(i, j, v));
				print(v);
			}
			
		}
	}
	sort(answer.begin(), answer.end()); 
	cout << answer.size() << "\n";
	for (int i : answer) {
		cout << i <<"\n";
	}
	return 0;
}