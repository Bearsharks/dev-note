#include <iostream>
#include <string> 
using namespace std;

typedef unsigned long long ull;


ull myPow(ull x, ull p){
	if (p == 0) return 1;
	ull tmp = x;
	while (--p) {
		x *= tmp;
	}
	return x;
}

ull getNum(string n) {
	if (n.size() == 1) return n[0]-'0';
	ull num = stoull(n, nullptr, 0);
	int rm = n.back() - '0';
	int lm = n[0] - '0';
	int nod = n.size();
	ull result = 0;

	for (int i = 0; i < nod - 2; i++) {
		result = result * 10 + 9;
	}

	result += 9 + ((num - rm) / 10 - myPow(10, nod - 2));
	if (lm <= rm) {
		result++;
	}
	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long mn;
	string mx;
	cin >> mn >> mx;
	ull test = getNum(mx);
	ull test2 = getNum(to_string(mn - 1));
	cout << getNum(mx) - getNum(to_string(mn - 1));
	return 0;
}