#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> ns(n+1);
	vector<int> ms(m+1);
	for (int i = 1; i <= n; i++) {
		cin >> ns[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> ms[i];
	}
	
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		sum += ms[i];
		ns[i] += sum;
	}
	int k = 0;
	int mns = 0;
	for (int i = n-m+1; i <= n; i++) {
		mns += ms[k++];
		ns[i] -= mns;
	}
	for (int i = m + 1; i <= n; i++) {
		ns[i] += sum;
	}


	for (int i = 1; i <= n; i++) {
		cout << ns[i] % c << " ";
	}
	return 0;
}