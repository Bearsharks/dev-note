/*
한번에 하나의 일만 할 수 있고,
몇일에 시작해서 몇일에 끝나는 일을 하면 받은 돈이 얼마라고 알려져 있을때,
돈을 최대로 얼마까지 벌수 있나를 물어보는 문제

간단한데 한가지 주목할 점은 일정 이상으로 하면 안될때는 분기해서 안가게 했다는 점
괜히 리턴값을 바꾸거나 해서 형식을 바꾸면 곤란하다는 것이다.
*/
#include <iostream>
#include <vector>
using namespace std;


vector<int> t(15);
vector<int> p(15);
vector<int> dp(15, -1);
int N;
int f(int k) {
	if (k >= N) return 0;
	int& ret = dp[k];
	if (ret >= 0) return ret;
	ret = 0;
	if (t[k] + k - 1 < N) {
		ret = max(ret, p[k] + f(t[k] + k));		
	}	
	ret = max(ret, f(k + 1));
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
	}	
	cout << f(0);
	return 0;
}