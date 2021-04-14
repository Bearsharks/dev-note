#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) v.push_back({ i,a[i] });
	}

	int size = v.size();
	int cnt = 0;
	for(int i = 1; i < size ; i ++){
		if (v[i].first - v[i - 1].first == 1 && v[i].second != v[i - 1].second) {
			cnt++;
			i++;
		}
	}
	cout << size - cnt;

	return 0;
}