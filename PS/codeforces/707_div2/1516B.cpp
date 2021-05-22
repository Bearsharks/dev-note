#include <iostream>
#include <vector>
using namespace std;
/*
배열에서 인접 원소 두개를 xor해서 하나로 만드는 것을 반복해서
모든 원소들을 동일하게 만들 수 있는가?
모두 xor했을 때 0이 되면 동일하게 만들 수 있는 것
그렇지 않다면 원소를 3개로 만들었을때 동일하게 만들 수 있는 지 확인
배열을 세가지로 쪼개는 모든 방법을 시도했을때, 모두 동일하면 가능 아니면 불가능

주목해야할점
답은 2개나 3개로 항상 만들 수 있다는 것을 발견하기 왜냐하면 4개 5개... 의 갯수로 된다면
짝수개라면 두개로 만들어서 0으로 만들수 있기 때문에 
홀수 개라면 남는거 따로 두면 두개로 만들 수 있기 때문에

답이 되는 것이 2가 될 수 있다면 모두 xor 하면 0이 된다는 것
a xor a = 0 이기 때문에

a xor b xor b  = a라는 성질이 있다.
결국 xor특성을 잘 알면 충분히 해결할수 있는 문제였다.
*/
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> xordp(n);
		long long test = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			test = test ^ v[i];
			xordp[i] = test;
		}
		if (test == 0) {
			cout << "YES\n";
			continue;
		}

		bool result = false;
		for (int i = 0; i < n - 2 && !result; i++) {
			long long test1 = xordp[i];			
			for (int j = i+1; j < n - 1; j++) {
				long long test2 = xordp[j] ^ xordp[i];
				long long test3 = xordp[n-1] ^ xordp[j];
				if (test1 == test2 && test2 == test3) {
					result = true;
					break;
				}
			}			
		}
		if (result) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}		
	}

	return 0;
}