#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<bool> v(10001);
	vector<int> m(10001);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		v[a] = true;
		m[a]++;
	}
	for (int i = 1; i < 10001; ++i) {
		if (v[i] == true) {
			for (int j = 0; j < m[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}