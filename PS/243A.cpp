#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<unsigned long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<unsigned long long> cur;
	unordered_set<unsigned long long> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0,size = cur.size(); j < size ; j++) {
			cur[j] = (cur[j] | v[i]);
		}
		cur.push_back(v[i]);
		int curpos = 1;
		unsigned long long prev = cur[0];
		for (int j = 1, size = cur.size(); j < size; j++) {
			if (cur[j] != prev) {
				cur[curpos] = cur[j];
				prev = cur[curpos];
				curpos++;
			}
		}
		for (int j = 0; j < curpos;j++) {
			s.insert(cur[j]);
		}
		while (cur.size() != curpos) {
			cur.pop_back();
		}
	}
	
	cout << s.size();
	return 0;
}