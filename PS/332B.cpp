#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	vector<long long> d;
	d.push_back(sum);
	for (int i = k; i < n; i++) {
		d.push_back(d.back() + v[i] - v[i - k]);
	}
	vector<long long> segmentmax(d.size());
	segmentmax.back() = d.size() - 1;
	for (int i = d.size() - 2; i >= 0; i--) {
		segmentmax[i] = (d[segmentmax[i + 1]] > d[i]) ? segmentmax[i + 1] : i;
	}
	long long max = 0;
	int first, second;
	for (int i = 0; i + k < d.size(); i++) {
		if (max < d[i] + d[segmentmax[i + k]]) {
			max = d[i] + d[segmentmax[i + k]];
			first = i;
			second = segmentmax[i + k];
		}
	}
	cout << first + 1 << " " << second + 1;
	return 0;
}	