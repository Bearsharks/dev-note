#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long ull;

void sett(map<ull,ull>& t, ull p ) {
	map<ull, ull>::iterator next = t.upper_bound(p);
	map<ull, ull>::iterator prev = next;
	prev--;

	bool prevMerge = false;
	if (prev != t.end()){
		prevMerge = p - prev->second == 1;
	}
	bool nextMerge = next->first - p == 1;

	if (!prevMerge && !nextMerge){
		t.insert({ p,p });	
	}
	else if (prevMerge && nextMerge) {
		pair<ull, ull> mergedp = { prev->first, next->second };
		t.erase(prev);
		t.erase(next);
		t.insert(mergedp);
	}
	else if (prevMerge) {
		ull first = prev->first;
		t.erase(prev);
		t.insert({ first,p });
	}
	else if (nextMerge) {
		ull last = next->second;
		t.erase(next);
		t.insert({p,last});
	}
}

void initt(map<ull, ull>& t, vector <ull>& v, ull l) {
	for (int i = 0, size = v.size(); i < size;i++) {
		if (v[i] > l) {
			ull prev = i;
			for (; i < size; i++) {
				if (i == size - 1 || v[i + 1] <= l) {
					t.insert({ prev, i });
					break;
				}
			}
		}		
	}
	t.insert({ -1, -1});
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,l;
	cin >> n >> m >> l;
	
	vector<ull> v(n+1);
	vector<int> isSetted(n+1);
	map<ull,ull> t;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] > l) {
			isSetted[i] = 1;
		}
	}

	initt(t,v,l);

	for (int i = 0; i < m; i++) {
		char oper;
		cin >> oper;
		if (oper == '0') {
			cout << t.size()-1 << "\n";
		}
		else {
			int p, d;
			cin >> p >> d;
			v[p] += d;
			if (!isSetted[p] && v[p] > l) {
				isSetted[p] = 1;
				sett(t,p);
			}
		}
	}
	return 0;
}