#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int h,w;
	vector<vector<int>> hor(500, vector<int>(500));
	vector<vector<int>> ver(500, vector<int>(500));
	cin >> h >> w;	
	vector<string> v(h);
	for(int i = 0 ; i<h;i++){
		cin >> v[i];
	}

	hor[0][0] = 0;
	for (int j = 1; j < w; j++) {
		hor[0][j] += hor[0][j - 1] + (v[0][j - 1] == '.' && v[0][j] == '.');
	}
	for (int i = 1; i < h; i++) {
		hor[i][0] = 0;
		for (int j = 1; j < w; j++) {
			hor[i][j] += hor[i][j - 1] + (v[i][j-1] == '.' && v[i][j] == '.');
		}
		for (int j = 1; j < w; j++) {
			hor[i][j] += hor[i - 1][j];
		}
	}
	ver[0][0] = 0;
	for (int i = 1; i < h; i++) {
		ver[i][0] += ver[i - 1][0] + (v[i - 1][0] == '.' && v[i][0] == '.');
	}
	for (int j = 1; j < w; j++) {
		ver[0][j] = 0;
		for (int i = 1; i < h; i++) {
			ver[i][j] += ver[i - 1][j] + (v[i-1][j] == '.' && v[i][j] == '.');
		}
		for (int i = 1; i < h; i++) {
			ver[i][j] += ver[i][j-1];
		}
		
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1>> r2>> c2;
		r1--; c1--; r2--; c2--;
		int one = hor[r2][c2] - hor[r2][c1] + ((r1 - 1 >= 0)? hor[r1 - 1][c1] - hor[r1 - 1][c2] : 0);
		int two = ver[r2][c2] - ver[r1][c2] + ((c1-1 >= 0) ? ver[r1][c1 - 1] - ver[r2][c1 - 1]  : 0);
		cout << one + two << "\n";
	}
	
	return 0;
}