#include <iostream>
#include <vector>
#include <set>
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

int getCandi(int init, int cnt, int digit) {
	int candi = init;
	for (int i = 0; i < cnt; i++) {
		candi *= 10;
		candi += digit;
	}
	return candi;
}

int getpushnum(int num, int tgt) {
	return abs(num - tgt) + getdigitnum(num);
}

int getnext(int num, vector<int>& btns) {
	for (int i = num + 1; i < 10; i++) {
		if (btns[i]) return i;
	}
	return 10;
}

int getprev(int num, vector<int>& btns) {
	for (int i = num - 1 ; i >= 0; i--) {
		if (btns[i]) return i;
	}
	return -1;
}
int getNextNum(vector<int>& digits, vector<int>& btn, int i) {
	int res = 0;
	while (i >= 0 && getnext(digits[i], btn) > 9) {
		i--;
	}
	if (i == -1) {//앞의 모든 자리수가 최대라면
		res = getCandi(getnext(0, btn), digits.size(), getnext(-1, btn));
	}
	else {
		int init = 0;
		for (int j = 0; j < i; j++) {
			init *= 10;
			init += digits[j];
		}
		init *= 10;
		init += getnext(digits[i], btn);
		res = getCandi(init, digits.size() - (i + 1), getnext(-1, btn));
	}
	return res;
}
int getPrevNum(vector<int>& digits, vector<int>& btn, int i) {
	int res = 0;
	while (i < digits.size() && getprev(digits[i], btn) < 0) {
		i--;
	}
	if (i == -1) {//앞의 모든 자리수가 최소라면
		res = getCandi(0, digits.size()-1, getprev(10, btn));
	}
	else {
		int init = 0;
		for (int j = 0; j < i; j++) {
			init *= 10;
			init += digits[j];
		}
		init *= 10;
		init += getprev(digits[i], btn);
		res = getCandi(init, digits.size() - (i + 1), getprev(10, btn));
	}
	return res;
}

int ca(vector<int>& btn, int tgt) {
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
	int cnt = 0;
	for (int i : digits) {
		cnt += btn[i];
	}
	
	if (cnt == digits.size()) {
		//버튼눌러서 바로 갈수 있는 경우
		ans = min(ans, (int)digits.size());
		return ans;
	}

	if (getnext(-1, btn) > 9) {
		//절대 버튼 눌러서 갈수 없는 경우
		return ans;
	}
	else if (getnext(0, btn) > 9) {
		//버튼 눌러서 갈 수 있는게 0밖에 없으므로
		ans = min(ans, getpushnum(0, tgt));
		return ans;
	}
	//하나라도 문제가 있으면
	for (int i = 0; i < digits.size(); i++) {
		if (!btn[digits[i]]) {
			int next = getNextNum(digits, btn, i);
			int prev = getPrevNum(digits, btn, i);
			ans = min(ans, getpushnum(next, tgt));
			if (!(prev == 0 && getnext(-1, btn) > 0)) {
				//prev 가 0인데 정작 0이 못나오는 상황이면 하지 않음
				ans = min(ans, getpushnum(prev, tgt));
			}
			break;
		}
	}
	return ans;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int tgt, m;
	cin >> tgt >> m;
	vector<int> btn(10,1);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		btn[a] = 0;
	}
	cout << ca(btn, tgt);
	return 0;
}