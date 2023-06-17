#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

inline int Int(char c) {
	return c - '0';
}
inline int timeToInt(string s) {
	return (Int(s[0]) * 10 + Int(s[1])) * 60 + Int(s[3]) * 10 + Int(s[4]);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string ss, es, dds;
	cin >> ss >> es >> dds;
	int s = timeToInt(ss);
	int e = timeToInt(es);
	int dd = timeToInt(dds);
	
	unordered_set<string> atts;
	unordered_set<string> result;
	while (!cin.eof()) {
		string timestr, name;
		cin >> timestr >> name;
		int time = timeToInt(timestr);
		if (time <= s) {
			atts.insert(name);
		}
		else if (time >= e && time <= dd && atts.count(name)) {
			result.insert(name);
		}
	}

	cout << result.size();
	return 0;
}