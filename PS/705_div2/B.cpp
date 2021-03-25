#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

bool test(int t) {
	return t == 0 || t == 1 || t == 2 || t == 5 || t == 8;
}

int rev(int t) {
	if (t == 2) return 5;
	if (t == 5) return 2;
	return t;
}

bool isGood(int t, int limit) {
	int t1 = t / 10;
	int t2 = t % 10;
	if (test(t1) && test(t2)) {
		return (rev(t2) * 10 + rev(t1) < limit);
	}
	return false;
}

int next(int t) {
	if (t < 1) return 1;
	if (t < 2) return 2;
	if (t < 5) return 5;
	if (t < 8) return 8;
	return 0;
}

string nextGood(int t,int limith, int limitm) {
	int t1 = t / 10;
	int t2 = t % 10;

	t2 = next(t2);
	if (t2 == 0) t1 = next(t1);

	while (t1 * 10 + t2 < limith && !isGood(t1 * 10 + t2, limitm)){
		if (t2 == 0) {
			t1 = next(t1);
		}
		else {
			t2 = next(t2);
			if (t2 == 0) {
				t1 = next(t1);
			}
		}
	}

	if (t1 * 10 + t2 >= limith) return "00";

	string res = "00";
	res[0] += t1;
	res[1] += t2;
	return res;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int h, m;
		string time;
		cin >> h >> m >> time;
		int HH = (time[0] - '0') * 10 + time[1] - '0';
		int MM = (time[3] - '0') * 10 + time[4] - '0';
		if (!isGood(HH, m)) {
			cout << nextGood(HH, h, m) << ":00\n";
		}
		else if (isGood(MM, h)) {
			cout << time << "\n";
		}		
		else {
			string nextm = nextGood(MM, m, h);
			if (nextm == "00") {
				cout << nextGood(HH, h, m) << ":00\n";
			}
			else {
				cout << time[0] << time[1] << ":" << nextm << "\n";
			}
		}
	}
	return 0;
}