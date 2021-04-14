#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		if (k == 1) {
			cout << s << "\n";
			continue;
		}
		if (n % k) {
			cout << -1 << "\n";
			continue;
		}
		map<int, int> m;
		for (int i = 0; i < k; i++) {
			m[s[i]]++;
		}


		for (map<int, int>::iterator iter = m.begin(); iter != m.end();iter++) {
			iter->second *= (n / k - 1);
		}

		bool isok = true;
		for (int i = k; i < n; i++) {
			map<int,int>::iterator iter = m.lower_bound(s[i]);
			if (iter == m.end()) {
				//현재 글자가 앞의 모든 글자보다 큰경우
				string cp = s.substr(k,i);
				//처음 부터 현재까지 substr의 다음 사전순 문자열을 구해서 (next_permu)
				next_permutation(s.begin() + k, s.begin() + i);
				bool issame = cp == s.substr(k, i);
				//둘이 같으면 뒤문자열로는 처리 불가능
				if (issame) {
					isok = false;
					break;
				}				
				//다르면 뒤에 남은거 붙여서 출력함
				for (pair<int, int> p : m) {
					for (int j = 0; j < p.second; j++) {
						s[i++] = p.first;
					}
				}
				break;
			}
			else if (iter->first != s[i]) {
				//현재 글자가 앞문자열의 특정 글자 보다 작은경우
				s[i] = iter->first;//현재글자를 특정글자로 만들고 뒤에는 남은거 붙여서 출력
				iter->second--;
				for (pair<int, int> p : m) {
					for (int j = 0; j < p.second; j++) {
						s[++i] = p.first;
					}
				}
				break;
			}
			if (--iter->second == 0) m.erase(iter);
		}
		if (isok) cout << s << "\n";
		else {
			//뒤의 문자열로 처리 불가능하면
			//앞의 문자열을 바꿔서 처리함
			int cur = k - 1;
			while (s[cur] == 'z') {
				cur++;
			}
			s[cur]++;
			string piece = s.substr(0, k);
			cout << piece;
			sort(piece.begin(), piece.end());
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < (n / k)-1; j++) {
					cout << piece[i];
				}				
			}
			cout << "\n";
		}		
	}
	return 0;
}