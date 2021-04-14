#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef unsigned long long ull;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> s;
	vector<int> v(n+1);
	vector<int> cap(n+1);
	
	for (int i = 1; i <= n; i++) {
		cin >> cap[i];
		s.insert(i);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int kind;
		cin >> kind;
		if (kind == 1) {
			int a, li;
			cin >> a >> li;
			set<int>::iterator cur = s.lower_bound(a);
			while (cur != s.end() && li > 0) {
				v[*cur] += li;
				li = v[*cur] - cap[*cur];
				if (v[*cur] >= cap[*cur]) {					
					v[*cur] = cap[*cur];
					cur = s.erase(cur);
				}
			}
		}
		else {
			int a;
			cin >> a;
			cout << v[a] << "\n";
		}
	}
	return 0;
}