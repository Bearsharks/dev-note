#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int w,h,n;
	cin >> w >> h >> n;
	set<int> vs, hs;
	map<int, int> vm, hm;
	vs.insert(0); vs.insert(w);
	hs.insert(0); hs.insert(h);
	vm[w] = 1;
	hm[h] = 1;
	while (n--) {
		char a;
		int b;
		cin >> a >> b;
		if (a == 'V') {
			set<int>::iterator r = vs.upper_bound(b);
			set<int>::iterator l = r; l--;
			int d = *r - *l;
			vm[*r - b]++;
			vm[b - *l]++;
			if (--vm[d] == 0) {
				vm.erase(d);				
			}
			vs.insert(b);
		}
		else {
			set<int>::iterator r = hs.upper_bound(b);
			set<int>::iterator l = r; l--;
			int d = *r - *l;
			hm[*r - b]++;
			hm[b - *l]++;
			if (--hm[d] == 0) {
				hm.erase(d);				
			}
			hs.insert(b);
		}
		cout << (long long)vm.rbegin()->first * hm.rbegin()->first << "\n";
	}
	return 0;
}