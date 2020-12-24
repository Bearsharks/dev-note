#include <iostream>
#include <vector>
using namespace std;

struct da {
	int first;
	int second;
	int f;
};
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<da> v(200004);
	int left = 0, right = 0;
	while (n--) {
		char c;
		int id;
		cin >> c >> id;
		if (c == 'L') {
			left++;
			v[id] = { left,right,0};
		}
		else if (c == 'R') {
			right++;
			v[id] = { left,right, left+right-1};
		}
		else {
			int nf = left - v[id].first + v[id].f;
			int nb = right + v[id].first - 1 - v[id].f;
			cout <<( (nf < nb) ? nf : nb);
			cout << "\n";
		}
	}
	return 0;
}