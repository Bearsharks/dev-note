#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
ull doSomething(ull v, ull k) {
	ull result = 0;
	ull i = 1;
	while (v >= i) {
		result += v / i;
		i *= k;
	}
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ull n, k;
	cin >> n >> k;
	

	int min = ceil(n * (k - 1) / (double)k);
	int max = n;
	
	
	while (max > min) {
		int mid = (max + min) / 2;
		if (doSomething(mid, k) < n){
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}
	cout << max;

	return 0;
}