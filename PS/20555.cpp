/*
로봇이 1에서 타고 n에서 내리는 총 2n길이 벨트가 돈다
타는데 그리고 이동 목표는 내구도가 든다.
회전 타고 내리고 다음칸에 로봇이 없고 내구도가 있으면 로봇이 한칸가는 것을 반복할때
0인 내구도가 k개 이상이면 종료된다. 종료될때까지 몇번 하는가?
*/

#include <iostream>
#include <vector>
using namespace std;

int getidx(int src, int n) {
	src = src % n;
	return (src < 0)? n+src : src;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(2 * n);
	vector<bool> isEmpty(2 * n, true);
	for (int i = 0; i < 2*n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	int t = 0;
	while (cnt < k) {
		t++;
		int start = getidx(-t, 2 * n);
		int end = getidx(start + n-1, 2 * n);
		if (!isEmpty[end]) isEmpty[end] = true;		
		for (int i = end; i != start && cnt < k; i = getidx(i - 1, 2 * n)) {
			if (isEmpty[i]) continue;

			int next = getidx(i + 1, 2 * n);
			if (isEmpty[next] && v[next]) {
				isEmpty[i] = true;
				isEmpty[next] = false;
				v[next]--;
				if (v[next] < 1) cnt++;
				if (next == end) isEmpty[next] = true;
			}
		}
		if (v[start] > 0) {
			v[start]--;
			isEmpty[start] = false;
			if (v[start] == 0) cnt++;
		}
	}
	cout << t;
	return 0;
}