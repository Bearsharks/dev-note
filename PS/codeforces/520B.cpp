#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long d = 1e9 + 7;
unsigned long long power(int a,int n) {
	unsigned long long result = a;
	while (--n) {
		result = (result * a) % d;
	}
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	vector<int> count(26);
	for (char c : s) {
		count[c - 'A']++;
	}
	sort(count.begin(), count.end());
	if (count[25] > count[24]) {
		cout << 1;
	}
	else if (count[24] > count[23]) {
		cout << power(2,n);
	}
	else if (count[23] > count[22]) {
		cout << power(3, n);
	}
	else if (count[22] > count[21]) {
		cout << power(4, n);
	}

	return 0;
}