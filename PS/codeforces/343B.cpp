#include <iostream>
#include <stack>
using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();

	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (st.top() == s[i]) st.pop();
			else st.push(s[i]);
		}
	}
	if (!st.empty()) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	
	return 0;
}