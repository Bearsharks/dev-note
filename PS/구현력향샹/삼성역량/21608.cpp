/*
* 반인원이 모두 각자 친구 4명씩 있는 반에서
* 자리배정할때 1 친구 가장 많은 곳 2 가장 주변이 (상하좌우)비어있는 곳 3 행렬이 가장 작은 곳을
* 입력들어오는 순으로 각각 배정 할때, 만족도 구하는 문제
* 
* 다 잘풀었는데 조건에 맞는지 확인 할 때, 초기 mx값을 0으로 둬서 틀렸다. 0이 나올수도 있는데
* 0으로 뒀기 때문에 0인경우는 무시하게 되고 그래서 틀리게 된다. 초기 mx값을 확인하자
* 
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void initBoard(vector<vector<bool>>& board, int n) {
	for (int j = 0; j < n + 2; j++) {
		board[0][j] = true;
		board[n + 1][j] = true;
		board[j][0] = true;
		board[j][n + 1] = true;
	}
}
vector<pair<int, int>> getMostLike(map<pair<int, int>, int>& m) {
	int mx = 0;
	vector<pair<int, int>> mostlike;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > mx) {
			mx = iter->second;
			mostlike.clear();
		}
		if (iter->second == mx) {
			mostlike.push_back(iter->first);
		}
	}
	return mostlike;
}
vector<pair<int, int>> getMostEmpty(vector<pair<int, int>>& mostlike, vector<vector<bool>>& board) {
	int mx = 0;
	vector<pair<int, int>> mostempty;
	for (auto curpos = mostlike.begin(); curpos != mostlike.end(); curpos++) {
		int emptyadj = 0;
		for (int k = 0; k < 4; k++) {
			int nexti = curpos->first + dx[k];
			int nextj = curpos->second + dy[k];
			if (board[nexti][nextj] == false) emptyadj++;
		}
		if (emptyadj > mx) {
			mx = emptyadj;
			mostempty.clear();
		}
		if (emptyadj == mx) {
			mostempty.push_back(*curpos);
		}
	}
	return mostempty;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n * n + 1, vector<int>(4));
	vector<pair<int, int>> pos(n * n + 1, { 0,0 });
	vector<vector<bool>> board(n + 2, vector<bool>(n + 2));
	initBoard(board, n);
	for (int i = 0; i < n * n; i++) {
		int cur;
		cin >> cur;
		vector<int>& like = v[cur];
		cin >> like[0] >> like[1] >> like[2] >> like[3];
		map<pair<int, int>, int> m;
		for (int j = 0; j < 4; j++) {
			//like위치를 pos에서 찾아서 그 위치 상하좌우가 비었다면 후보로 넣음
			pair<int, int> likepos = pos[like[j]];
			if (likepos.first == 0 && likepos.second == 0) continue;
			for (int k = 0; k < 4; k++) {
				int nexti = likepos.first + dx[k];
				int nextj = likepos.second + dy[k];
				if (board[nexti][nextj] == false) m[{nexti, nextj}]++;
			}
		}
		pair<int, int> mypos = { 987654321, 987654321 };
		if (!m.empty()) {
			//가장 큰 수를 가진 것들을 필터링함
			vector<pair<int, int>> mostlike = getMostLike(m);
			
			//그 중 가장 주변이 빈 곳이 많은 곳으로 필터링함
			vector<pair<int, int>> mostempty = getMostEmpty(mostlike, board);
			
			//그중 가장 행렬이 작은 곳을 고름
			for (pair<int, int> p : mostempty) {
				mypos = min(mypos, p);
			}
			
		}
		else {
			//앞에서 뒤로 가면서 빈 곳 중에 주변 빈 곳이 가장 많은 곳을 고름 처음으로 4개가 됬다면 탈출함
			int mx = -1;
			for (int k = 1; k <= n && mx < 4; k++) {
				for (int h = 1; h <= n && mx < 4; h++) {
					if (board[k][h] == false) {
						int curempty = 0;
						for (int t = 0; t < 4; t++) {
							int nexti = k + dx[t];
							int nextj = h + dy[t];
							if (board[nexti][nextj] == false) curempty++;
						}
						if (mx < curempty) {
							mx = curempty;
							mypos = { k,h };
						}
					}					
				}
			}
		}
		pos[cur] = mypos;
		
		board[mypos.first][mypos.second] = true;
	}

	//선호도 계산
	int answer = 0;
	for (int i = 1; i <= n * n; i++) {
		set<pair<int, int>> s;
		pair<int, int> mypos = pos[i];
		s.insert({ mypos.first - 1, mypos.second });
		s.insert({ mypos.first, mypos.second + 1 });
		s.insert({ mypos.first + 1, mypos.second });
		s.insert({ mypos.first, mypos.second - 1 });
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			cnt += s.count(pos[v[i][j]]);
		}
		if (cnt > 0) answer += pow(10, cnt - 1);
	}
	cout << answer;

	return 0;
}