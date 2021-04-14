#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);
	vector<int> score(n+1);
	for (int i = 1; i < n+1; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n+1; i++) {
		cin >> score[i];
	}
	int lastScore = v[k] + score[1];
	int cnt = 0;
	for (int i = 2; i < n + 1 && k - 1 > 0; i++) {
		if (lastScore >= score[i] + v[k - 1]) {
			k--;
		}
	}
	cout << k;
	return 0;
}