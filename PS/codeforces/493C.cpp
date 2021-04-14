#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int ans = -987654321;
int fresult, sresult;
vector<int> f;
vector<int> s;

void test(int a) {
	vector<int>::iterator ff = lower_bound(f.begin(), f.end(),a);
	vector<int>::iterator ss = lower_bound(s.begin(), s.end(), a);
	int fscore = (f.end() - ff) * 3 + (ff - f.begin()) * 2;
	int sscore = (s.end() - ss) * 3 + (ss - s.begin()) * 2;
	if (ans < fscore - sscore) {
		ans = fscore - sscore;
		fresult = fscore;
		sresult = sscore;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		f.push_back(a);
	}
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	sort(f.begin(), f.end());
	sort(s.begin(), s.end());	

	for (int i = 0; i < n; i++) {
		test(f[i]);
	}
	test(f.back() + 1);
	for (int i = 0; i < m; i++) {
		test(s[i]);
	}
	test(s.back() + 1);
	cout << fresult << ":" << sresult;
	return 0;
}