/*
배열에서 두개를 골랐는데 두개가 똑같은 수 라면 1을 더하는 것을
모든 연속부분배열 각각에서 했을 때 얼마인지 구하시오.

연속부분배열들이 있는데 어떤 연속부분배열에 그 다음 원소를 더해서 크기가 하나 더 큰 consubarr를 만들 수 있다.
그 consubarr에 추가된 원소가 원래꺼의 마지막 원소랑 다르다면 그 consubarr가 답에 기여하는 만큼은 원래꺼랑 똑같다.
만약 같다면, 원래꺼에 있는 거에서 마지막 원소 하나가 추가되서 생겨난 만큼을 더해주면 그 것이 답이다.
그 생겨난 만큼이 얼마나 일까 현재 i번째가 추가 되었고 j번째에 있는녀석과 같다면
ji j-1 i j-2 i ... 1 i 총 j개 만큼이 더 생겨날 것이다.
그러니까 같은 녀석이 여러개 일 수 있으므로 같은 녀석의 순서만큼이 새로 생겨날 것이다.
dp[i] = dp[i-1] + sigma(j) * arr[i] == arr[j]이고
답은 sigma(dp)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n ;
		vector<int> v(n);
		for (int i = 0; i < n;i++) {
			cin >> v[i];
		}
		vector<long long> dp(n);
		
		unordered_map<int, long long> m;
		dp[0] = 0;
		m[v[0]] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i - 1] + m[v[i]];
			m[v[i]] += i+1;
		}
		long long answer = 0;
		for (long long l : dp) {
			answer += l;
		}
		cout << answer << "\n";
	}
	return 0;
}