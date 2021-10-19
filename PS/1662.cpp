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
	//괄호를 스택에 쌓아서 만약 닫힌 괄호가 나오면 바로앞의 모인 문자의 갯수와
	//괄호 열때 같이 담은 숫자를 곱해서 압축된 문자열의 원래 길이를 얻는 것을 반복한다.
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