#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	string fibo[2] = { "0","1" };
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		string::iterator previ = fibo[i % 2].begin();
		int of = 0;
		stringstream newval;
		for (string::iterator iter = fibo[(i - 1) % 2].begin(); iter != fibo[(i - 1) % 2].end(); iter++) {
			int prev = (previ != fibo[i % 2].end())? *previ - '0' : 0;
			int cursum = *iter - '0' + prev + of;
			of = cursum / 10;
			if ((previ != fibo[i % 2].end())) {
				*previ = cursum % 10 + '0';
				previ++;
			}
			else {
				newval << cursum;
			}			
		}
		if (of) newval << of;
		fibo[i % 2] += newval.str();
	}
	reverse(fibo[n % 2].begin(), fibo[n % 2].end());
	cout << fibo[n % 2];
	return 0;
}