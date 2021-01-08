#include <iostream>
using namespace std;

bool result = true;
void type(string& ans) {
	string str;
	if (cin >> str) {
		ans += str;
		if (str == "pair") {
			ans += "<"; type(ans); ans += ","; type(ans); ans += ">";
		}			
	}
	else {
		result = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	type(str);

	string k = "test";
	while (!cin.eof()) {
		cin >> k;
	}

	if (result && k == "test") {
		cout << str;
	}
	else {
		cout << "Error occurred";
	}
	return 0;
}