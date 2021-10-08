#include <iostream>
#include <vector>
using namespace std;

int findNext(vector<int>& height, int prev) {
	int cur = prev + 1;
	int mx = 0;
	int idx = cur;
	while (cur < height.size()){
		if (height[prev] <= height[cur]) {
			return cur;
		}
		if (height[cur] >= mx) {
			mx = height[cur];
			idx = cur;
		}		
		cur++;
	}
	return idx;
}

int findPrev(vector<int>& height, int cur) {
	while (cur+1 < height.size()) {
		if (height[cur] > height[cur + 1]) {
			break;
		}
		cur++;
	}
	return cur;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	vector<int> v(c);
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	int answer = 0;
	int prev = findPrev(v,0);
	int next = findNext(v, prev);
	while (next < c) {
		int h = min(v[prev], v[next]);
		for (int i = prev + 1; i < next; i++) {
			answer += h - v[i];
		}
		prev = findPrev(v, next);
		next = findNext(v, prev);
	}
	cout << answer;

	return 0;
}