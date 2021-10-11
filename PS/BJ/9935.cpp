#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str, bomb;
	cin >> str >> bomb;
	vector<char> v = { 0 };
	string result = "";
	for (int i = 0; i < str.size();i++) {
		result.push_back(str[i]);
		if (bomb[v.back()] == str[i]) {
			v.push_back(v.back() + 1);
			if (v.back() == bomb.size()) {
				int n = v.back();
				while (n--) {
					v.pop_back();
					result.pop_back();
				}
			}
		}
		else {
			if (str[i] == bomb[0]) v.push_back(1);
			else v.push_back(0);
		}
	}
	if (result == "") result = "FRULA";
	cout << result;
	return 0;
}