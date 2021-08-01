#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> dp(101, vector<pair<int,int>>(101, { -987654321, 987654321 }));
pair<int, int> f(int s, int e, vector<string>& arr) {
	pair<int,int>& ret = dp[s][e];
	if (ret.first > -987654321 ) return ret;
	if (s == e) {
		int cur = stoi(arr[s * 2]);
		return ret = { cur , cur };
	}

	for (int i = s; i < e; i++) {
		pair<int, int> p1 = f(s, i, arr);
		pair<int, int> p2 = f(i + 1, e, arr);
		
		if (arr[i * 2 + 1] == "-") {			
			ret.first = max(p1.first - p2.second, ret.first);
			ret.second = min(p1.second - p2.first, ret.second);
		}
		else {
			ret.first = max(p1.first + p2.first, ret.first);
			ret.second = min(p1.second + p2.second, ret.second);
		}
	}	
	return ret;
}

int solution(vector<string> arr){
    return f(0, arr.size() / 2,arr).first;
}

int main() {
    cout << solution({ "1", "-", "3", "+", "5", "-", "8" });
    return 0;
}