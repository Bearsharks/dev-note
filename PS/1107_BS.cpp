#include <iostream>
#include <vector>
#include <algorithm>

#include <cmath>
using namespace std;

int getdigitnum(int k) {
	if (k == 0) return 1;
	int res = 0;
	while (k > 0) {
		k /= 10;
		res++;
	}
	return res;
}

int getpushnum(int num, int tgt) {
	return abs(num - tgt) + getdigitnum(num);
}
int getcandi(int n,vector<int>& btn) {
	int k = btn.size();
	int res = 0;	
	if (btn[0] == 0) {
		//진수계산
		int d = 1;
		while (n > 0) {
			res += btn[n % k] * d;
			d *= 10;
			n /= k;
		}
	}
	else {
		int idx = n % k;
		if (idx == 0) idx = k;
		res = btn[idx-1];
		int initpos = k;
		n -= k;
		int d = 10;		
		while (n > 0) {
			int idx = (n / initpos + !!(n % initpos)) % k;
			if (idx == 0) idx = k;
			res += btn[idx - 1] * d;
			d *= 10;
			initpos *= k;
			n -= initpos;			
		}
	}
	return res;
}
int BS(vector<int>& btn, int tgt) {
	int tmp = tgt;
	vector<int> digits;
	if (tgt == 0) {
		digits.push_back(0);
	}
	else {
		while (tmp > 0) {
			digits.push_back(tmp % 10);
			tmp /= 10;
		}
	}
	reverse(digits.begin(), digits.end());
	int ans = abs(tgt - 100);	
	if (btn.size() == 0) {
		//절대 버튼 눌러서 갈수 없는 경우
		return ans;
	}
	else if (btn.size() == 1 && btn[0] == 0) {
		//버튼 눌러서 갈 수 있는게 0밖에 없으므로
		ans = min(ans, getpushnum(0, tgt));
		return ans;
	}
	//하나라도 문제가 있으면
	int mx = max((int)digits.size() + 1, 2 * (int)pow(btn.size(), digits.size()));
	;
	int mn = (btn[0] == 0)? 0:1;
	while (mn < mx) {
		int mid = (mn + mx) / 2;
		int test = getcandi(mid, btn);
		if (test >= tgt) {
			mx = mid;
		}
		else {
			mn = mid + 1;
		}
	}
	//어퍼바운드이므로 현재 버튼으로 만들 수 있는 경우 mx-1이 답
	//없으면 mx가 tgt의 다음 수 mx-1이 이전수가 됨 둘중 하나가 답
	ans = min(ans, getpushnum(getcandi(mx, btn),tgt));
	if(mx > 0)ans = min(ans, getpushnum(getcandi(mx-1, btn),tgt));
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int tgt, m;
	cin >> tgt >> m;
	vector<int> v(10, 1);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v[a] = 0;
	}
	vector<int> btn;
	for (int i = 0; i < 10; i++) {
		if (v[i]) btn.push_back(i);
	}

	cout << BS(btn, tgt);


	return 0;
}