#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	while (!cin.eof()) {
		stack<char> st;
		for (char c : s) {
			if (c == '('|| c == '[') {
				st.push(c);
			}
			else if (c == ')' || c == ']') {
				if (st.empty()) {
					cout << 'NO\n';
					break;
				}
				else if (st.top() == '(' && c == ')') {
					st.pop();
					continue;
				}else if (st.top() == '[' && c == ']') {
					st.pop();
					continue;
				}
				else {
					cout << 'NO\n';
					break;
				}
			}
		}
		cin >> s;
	}
	return 0;
}