#include <iostream>
#include <tuple>
using namespace std;

class ������ {
public:
	virtual void �ŷ��Ѵ�(tuple<int, int, int, int> ��Ʈ) {};
	int �ڻ�(int �ְ�) {
		return �ְ� * �����ֽļ� + ��;
	}
protected:
	������() {}
	������(int money) :��(money) {}
	int �����ֽļ� = 0;
	int ��;
	void Ǯ�ż�(int �ְ�) {
		�����ֽļ� += (�� / �ְ�);
		�� -= (�� / �ְ�) * �ְ�;
	}
	void �����ŵ�(int �ְ�) {
		�� += �����ֽļ� * �ְ�;
		�����ֽļ� = 0;
	}
	
};

class �⵵�ϴ������� : public ������ {
public:
	�⵵�ϴ�������(int �ʱ��ڱ�): ������(�ʱ��ڱ�) {}

	void �ŷ��Ѵ�(tuple<int, int, int, int> ��Ʈ) {
		int ���簡 = get<3>(��Ʈ);
		if (���簡 <= ��) Ǯ�ż�(���簡);
	}
};

class Ÿ�̹������� : public ������ {
public:
	Ÿ�̹�������(int �ʱ��ڱ�) :������(�ʱ��ڱ�) {}
	void �ŷ��Ѵ�(tuple<int, int, int, int> ��Ʈ) {
		
		int ���簡 = get<3>(��Ʈ);
		bool �ȱ� = get<0>(��Ʈ) < get<1>(��Ʈ) && get<1>(��Ʈ) < get<2>(��Ʈ) && get<2>(��Ʈ) < get<3>(��Ʈ);
		if (�ȱ�) �����ŵ�(���簡);

		bool ��� = get<0>(��Ʈ) > get<1>(��Ʈ) && get<1>(��Ʈ) > get<2>(��Ʈ) && get<2>(��Ʈ) > get<3>(��Ʈ);
		if (���) Ǯ�ż�(���簡);
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int ��;
	cin >> ��;

	int chart[17];
	for (int i = 3; i < 17; i++) {
		cin >> chart[i];
	}
	chart[0] = chart[3];
	chart[1] = chart[3];
	chart[2] = chart[3];

	�⵵�ϴ������� ������(��);
	Ÿ�̹������� ������(��);
	for (int i = 3; i < 17; i++) {
		tuple <int, int, int, int> ���갣����Ʈ = { chart[i-3],chart[i-2] ,chart[i-1],chart[i] };
		������.�ŷ��Ѵ�(���갣����Ʈ);
		������.�ŷ��Ѵ�(���갣����Ʈ);
	}

	int ���������ְ� = chart[16];
	if (������.�ڻ�(���������ְ�) > ������.�ڻ�(���������ְ�)) cout << "BNP";
	else if (������.�ڻ�(���������ְ�) < ������.�ڻ�(���������ְ�)) cout << "TIMING";
	else cout << "SAMESAME";
	return 0;
}