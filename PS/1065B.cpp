#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long v,e;
	cin >> v >> e;
	
	long long mn = max(v - 2*e, (long long)0);

	long long con = 0;
	for (long long i = 1; i < v; i++) {
		long long candi = i * (i - 1) / 2;
		if (e > candi) {
			con = i + 1;
		}
		else {
			break;
		}
	}
	int mx = v - con;
	cout << mn << " "<<mx;
	return 0;
}