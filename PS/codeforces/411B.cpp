#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> cells(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cells[i][j];
		}
	}
	vector<int> core(n);
	unordered_set<int> lockedCell;
	for (int j = 0; j < m; j++) {
		unordered_map<int, int> cellInUse;
		for (int i = 0; i < n; i++) {
			if (core[i] == 0) {
				if (lockedCell.count(cells[i][j])) {
					core[i] = j + 1;
				}
				else if (cellInUse.count(cells[i][j])) {
					lockedCell.insert(cells[i][j]);
					core[cellInUse[cells[i][j]]] = j + 1;
					core[i] = j + 1;
					cellInUse.erase(cells[i][j]);
				}
				else if (cells[i][j]) {
					cellInUse[cells[i][j]] = i;
				}
			}
		}
	}
	for (int i : core) {
		cout << i << "\n";
	}
	return 0;
}