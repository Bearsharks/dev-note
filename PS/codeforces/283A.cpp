#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	int n;
	long long total = 0;
	int cnt = 1;
	cin >> n;
	vector<int> v = { 0 ,0};
	vector<int> save = { 0 ,0 };
	vector<double> ans;
	for (int i = 0; i < n; i++) {
		long long t,a,b;
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			v[a] += b;
			total += b*a;
		}
		else if (t == 2) {
			cin >> a;
			save.push_back(a);
			v.push_back(0);
			total += a;
			cnt++;
		}
		else if (cnt > 1) {			
			int last = v.back();
			total -= last;
			total -= save.back();
			save.pop_back();			
			v.pop_back();
			v.back() += last;
			cnt--;
		}
		ans.push_back((double)total / cnt);
	}
	cout.setf(ios::fixed);
	cout.precision(7);
	for (double d : ans) {
		cout << d << "\n";
	}
	return 0;
}