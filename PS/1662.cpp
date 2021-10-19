#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int INF = 987654321;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	//��ȣ�� ���ÿ� �׾Ƽ� ���� ���� ��ȣ�� ������ �ٷξ��� ���� ������ ������
	//��ȣ ���� ���� ���� ���ڸ� ���ؼ� ����� ���ڿ��� ���� ���̸� ��� ���� �ݺ��Ѵ�.
	int prevNumber = 1;
	int curStrSize = 0;
	stack<pair<int,int>> st;
	for (char c : s) {
		if (c == '(') {
			st.push({ prevNumber,curStrSize - 1 });
			curStrSize = 0;
		}
		else if (c == ')') {
			int repeatCnt = st.top().first;
			int prevStrSize = st.top().second;
			curStrSize *= repeatCnt;
			curStrSize += prevStrSize;
			st.pop();
		}
		else {
			prevNumber = c - '0';
			curStrSize++;
		}
	}
	cout << curStrSize;
	return 0;
}