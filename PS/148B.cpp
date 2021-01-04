#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	double ft = c / vp;//총 시간
	double ct = vp * t / (vd - vp); //용오는시간
	double ot = ct + t;//현재까지 시간
	double pp = ot * vp;//공주위치	

	do {
		ans++;
		double wt = ct + f;//낭비시간 가는 시간 창고에 넣는시간
		ct = (vp * wt + pp) / (vd - vp);
		ot += wt + ct;
		pp = ot * vp;
	} while (ft > ot);

	cout << ans;
	return 0;
}