#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int p, q;
	cin >> p >> q;

	vector<int> v(1e7 + 1);
	vector<int> primes;
	int cur = 1;
	while (1){
		bool isprime = true;
		for (int i = 0; primes[i] * 2 <= cur; i++) {
			if (cur % primes[i] == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) primes.push_back(cur);
	}
	for (int i = 2; i < 10000000; i++) {
		if(v[i] == 0) primes.push_back(i);
	}
	vector<int> palin;
	vector<int> palin;
	for (int i = 1; i <= 10000000; i++) {
		if (v[i] == 0) primes.push_back(i);
	}
	return 0;
}