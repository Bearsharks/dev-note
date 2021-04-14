#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getpartialmatch(string& n) {
	int begin = 1;
	int matched = 0;
	vector<int> res(n.size());
	while (begin + matched < n.size()) {
		if (n[begin + matched] == n[matched]) {
			matched++;
			res[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - res[matched - 1];
				matched = res[matched - 1];
			}
		}
	}
	return res;
}
vector<int> kmps(string& h, string& n) {
	vector<int> ret;
	vector<int> pi = getpartialmatch(n);
	int begin = 0;
	int end = h.size() - n.size();
	int matched = 0;
	while (begin <= end) {
		if (matched < n.size() && h[begin + matched] == n[matched]) {
			++matched;
			if (matched == n.size()) ret.push_back(begin);
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string  h, n;
	getline(cin, h);
	getline(cin, n);
	vector<int> ans = kmps(h, n);
	cout << ans.size();
	for (int i : ans) {
		cout << "\n" << i+1;
	}
	return 0;
}


