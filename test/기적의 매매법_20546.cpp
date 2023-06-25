#include <iostream>
#include <tuple>
using namespace std;

class 투자자 {
public:
	virtual void 거래한다(tuple<int, int, int, int> 차트) {};
	int 자산(int 주가) {
		return 주가 * 가진주식수 + 돈;
	}
protected:
	투자자() {}
	투자자(int money) :돈(money) {}
	int 가진주식수 = 0;
	int 돈;
	void 풀매수(int 주가) {
		가진주식수 += (돈 / 주가);
		돈 -= (돈 / 주가) * 주가;
	}
	void 전량매도(int 주가) {
		돈 += 가진주식수 * 주가;
		가진주식수 = 0;
	}
	
};

class 기도하는투자자 : public 투자자 {
public:
	기도하는투자자(int 초기자금): 투자자(초기자금) {}

	void 거래한다(tuple<int, int, int, int> 차트) {
		int 현재가 = get<3>(차트);
		if (현재가 <= 돈) 풀매수(현재가);
	}
};

class 타이밍투자자 : public 투자자 {
public:
	타이밍투자자(int 초기자금) :투자자(초기자금) {}
	void 거래한다(tuple<int, int, int, int> 차트) {
		
		int 현재가 = get<3>(차트);
		bool 팔까 = get<0>(차트) < get<1>(차트) && get<1>(차트) < get<2>(차트) && get<2>(차트) < get<3>(차트);
		if (팔까) 전량매도(현재가);

		bool 살까 = get<0>(차트) > get<1>(차트) && get<1>(차트) > get<2>(차트) && get<2>(차트) > get<3>(차트);
		if (살까) 풀매수(현재가);
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int 돈;
	cin >> 돈;

	int chart[17];
	for (int i = 3; i < 17; i++) {
		cin >> chart[i];
	}
	chart[0] = chart[3];
	chart[1] = chart[3];
	chart[2] = chart[3];

	기도하는투자자 준현이(돈);
	타이밍투자자 성민이(돈);
	for (int i = 3; i < 17; i++) {
		tuple <int, int, int, int> 나흘간의차트 = { chart[i-3],chart[i-2] ,chart[i-1],chart[i] };
		준현이.거래한다(나흘간의차트);
		성민이.거래한다(나흘간의차트);
	}

	int 마지막날주가 = chart[16];
	if (준현이.자산(마지막날주가) > 성민이.자산(마지막날주가)) cout << "BNP";
	else if (준현이.자산(마지막날주가) < 성민이.자산(마지막날주가)) cout << "TIMING";
	else cout << "SAMESAME";
	return 0;
}