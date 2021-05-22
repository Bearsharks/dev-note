#include <iostream>
#include <vector>
using namespace std;
/*
	문자열이 TMT의 조합으로 이뤄져 있는지 확인하는 문제
	예를들어 TTMTMT면 가능 MTT면 불가능
	
	각 M에 대해서 양옆의 T에 매칭 될 수 있는지를 확인한다.
	왼쪽 T는 T가 온다음에 M이 오기 때문에
	왼쪽에서 오른쪽으로 하나씩 M과 매칭시켜가면 될것같다.
	그 T들을 모두 지운뒤에 남은 T들은 첫번째 M의 제일 가까운 오른쪽T부터 하나씩 매칭시키면 될 것 같다.

	정말 그런지 보자 그리디는 답이되는 것을 생각한 뒤에 그것이 나의 가정에 맞게 변형시킬수 있음을 보이면
	타당한지 증명 할 수 있다. 
	
	일단 그리디로 고를 때 특정 m의 왼쪽에 있는 것에서 하나 고르고 오른쪽에 있는 것 안에서 하나 고르고 
	답 중 하나도 그런식으로 되어있다.
	답에서 가장 왼쪽에 있는 것이 아니라 다른 것을 골랐다면, 가장 왼쪽에 있는 것으로 바꿔도 문제없다.
	왜냐하면 답에서 mi의 왼쪽에 있는 것중에 하나 골랐고, 그것은 mj의 왼쪽에 있는 것이기도 하기 때문에 (i<j)
	가장 왼쪽에 있는 것이 아니라면 가장 왼쪽에 있는 것으로 바꾸고 원래 T를 mj에게 주면 되기 때문이다. 그래도 답이 된다.
	오른쪽의 경우도 그렇다.

 */
bool isok(int n, string str) {
	vector<pair<int, int>> v;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'T') {
			v.push_back({ i,0 });
		}
		else {
			if (v.size() > cur) {
				v[cur].second = i;
				cur++;
			}
			else {
				return false;
			}
		}
	}
	
	if (v.size() != cur * 2) return false;
	cur--;
	while (cur >= 0) {
		if(v[cur--].second > v.back().first) return false;
		v.pop_back();
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int l = -1;
		int r = n;
		if (isok(n, str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}	
		
	}
	return 0;
}