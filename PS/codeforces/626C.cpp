#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int two, three;
	cin >> two >> three;
	int cur = max(two*2,three*3);
	int a = cur/2;
	int b = cur/3;
	int c = cur/6;
	while (a < two || b < three || a + b - c < two + three) {
		cur++;
		if (cur % 2 == 0) a++; 
		if (cur % 3 == 0) b++;
		if (cur % 6 == 0) c++;		
	}
	cout << cur;
	return 0;
}