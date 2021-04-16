#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	vector<long long> v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum < s) {
		cout << 0;
		return 0;
	}
	int answer = n;
	long long cur = 0;
	int l = 0;
	for (int i = 0; i < n; i++) {
		cur += v[i];
		while (cur >= s) {
			answer = min(answer, i - l + 1);
			cur -= v[l++];			
		}
	}
	cout << answer;
	return 0;
}