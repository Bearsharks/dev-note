/*
* 
#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	return 0;
}
//printf("%.9f %.9f\n", cur.first, cur.second);
//scanf("%lf %lf %d", &a, &d, &n);
//v[1~n]에서 longest increasing subsequence를 구하는 알고리즘
vector<int> ans = { -1,INT_MAX };
for (int i = 1; i <= n; i++) {
    int min = 0;
    int max = ans.size()-1;
    while (min < max) {
        int mid = (min + max) / 2;

        if (ans[mid] < v[i]) {
            min = mid + 1;
        }
        else if (ans[mid] > v[i])  {
            max = mid;
        }
        else {
            break;
        }
    }
    if (max == ans.size() - 1) {
        ans.push_back(INT_MAX);
    }
    ans[max] = v[i];
}

int isvisit[50][50] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector<string> v(50);

bool dfs(pair<int, int> start, pair<int, int> cur) {
	isvisit[cur.first][cur.second] = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m
            && !isvisit[nextx][nexty] && dfs(start, { nextx, nexty }) )
        {
			return true;
		}
	}
	return false;
}

*/
