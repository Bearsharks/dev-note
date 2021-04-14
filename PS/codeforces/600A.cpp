#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> idxs;
	for (int i = 0; i < n; i++) {
		if (s[i] == ';' || s[i] == ',') idxs.push_back(i);		
	}
	vector<string> v;
	int prev = 0;
	for (int i = 0,size = idxs.size(); i < size; i++) {
		v.push_back(s.substr(prev, idxs[i] - prev));
		prev = idxs[i] + 1;
	}
	v.push_back(s.substr(prev));
	stringstream ss[2];
	ss[0] << "\"";
	ss[1] << "\"";
	for (int i = 0, size = v.size(); i < size; i++) {
		bool isint = false;
		if (v[i].size() > 0 && v[i][0] != '0' || v[i].size() == 1) {
			isint = true;
			for (char c : v[i]) {
				if ('0' > c || c > '9') {
					isint = false;
					break;
				}
			}
		}		
		ss[!isint] << v[i] << ",";
	}
	string a = ss[0].str();
	string b = ss[1].str();
	a.back() = '\"';
	b.back() = '\"';
	if (a.size() == 1) {
		a = "-";
	}
	if (b.size() == 1) {
		b = "-";
	}
	cout << a << "\n" <<b;
	return 0;
}