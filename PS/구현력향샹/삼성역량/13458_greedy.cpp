#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int b, c;
	cin >> b >> c;
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		v[i] -= b;
		answer++;
		if (v[i] > 0) {
			answer += v[i] / c + !!(v[i] % c);
		}
		
	}
	cout << answer;
	return 0;
}