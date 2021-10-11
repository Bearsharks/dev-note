#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mat(vector<vector<int>> a, vector<vector<int>> b) {
	int n = a.size();
	vector<vector<int>> v(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				v[i][j] += a[i][k] * b[k][j];
			}		
			v[i][j] %= 1000;
		}
	}
	return v;
}

vector<vector<int>> binpow(long long deg, vector<vector<int>>& matrix) {
	if (deg == 1) return matrix;
	if (deg % 2 == 1) return mat(binpow(deg - 1, matrix), matrix);
	vector<vector<int>> res = binpow(deg >> 1, matrix);
	return mat(res, res);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	long long b;
	cin >> n >> b;
	vector<vector<int>> v(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> answer = binpow(b, v);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}