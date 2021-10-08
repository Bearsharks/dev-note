#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	vector<int> v(c);
	vector<int> f;
	vector<int> b;
	int answer = 0;
	int pil = 0;
	for (int i = 0; i < c; i++) {
		cin >> v[i];
		if (f.size() == 0 || v[f.back()] <= v[i]) f.push_back(i);
	}
	for (int i = c-1; i > f.back(); i--) {
		if (b.size() == 0 || v[b.back()] <= v[i]) b.push_back(i);
	}
	reverse(b.begin(), b.end());
	for (int i : b) {
		f.push_back(i);
	}
	for (int i = 1; i < f.size(); i++) {
		if (f[i] - f[i - 1] > 1) {
			int height = min(v[f[i]], v[f[i - 1]]);
			for (int j = f[i - 1] + 1; j < f[i]; j++) {
				pil += v[j];
			}
			answer += height * (f[i] - f[i - 1] - 1);
		}
		
	}
	answer -= pil;
	cout << answer;
	return 0;
}