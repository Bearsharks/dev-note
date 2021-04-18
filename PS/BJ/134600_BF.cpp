#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<string>> v(11);
int answer = 11;
pair<int, int> D[4] = { {-1,0},{0,1},{1,0},{0,-1} };
void f(int cnt, int ri, int rj, int bi, int bj) {
	if (cnt >= answer) return;
	v[cnt] = vector<string>(v[cnt - 1]);
	
	for (int i = 0; i < 4; i++) {
		int nextri = ri, nextrj = rj, nextbi = bi, nextbj = bj;
		bool isMoved = false;
		bool isTouched = false;
		bool isRedOuted = false;
		do{
			nextri += D[i].first;
			nextrj += D[i].second;
		} while (v[cnt][nextri][nextrj] == '.');

		
		if (v[cnt][nextri][nextrj] == '#') {
			nextri -= D[i].first;
			nextrj -= D[i].second;
		}
		else if (v[cnt][nextri][nextrj] == 'B') {
			isTouched = true;
		}
		else if (v[cnt][nextri][nextrj] == 'O') {
			isRedOuted = true;
		}

		do {
			nextbi += D[i].first;
			nextbj += D[i].second;
		} while (v[cnt][nextbi][nextbj] == '.');

		if (v[cnt][nextbi][nextbj] == '#') {
			nextbi -= D[i].first;
			nextbj -= D[i].second;
			if (isTouched) {
				nextri = nextbi - D[i].first;
				nextrj = nextbj - D[i].second;
			}
		}
		else if (v[cnt][nextbi][nextbj] == 'R') {
			if (isRedOuted) continue;
			nextbi = nextri - D[i].first;
			nextbj = nextrj - D[i].second;			
		}
		else if (v[cnt][nextbi][nextbj] == 'O') {
			continue;
		}

		if (isRedOuted) {
			answer = min(answer, cnt);
			return;
		}

		isMoved = (bi != nextbi || bj != nextbj || ri != nextri || rj != nextrj);
		if (isMoved) {
			v[cnt][bi][bj] = '.';
			v[cnt][ri][rj] = '.';
			v[cnt][nextri][nextrj] = 'R';
			v[cnt][nextbi][nextbj] = 'B';
			f(cnt + 1, nextri, nextrj, nextbi, nextbj);
			v[cnt][nextri][nextrj] = '.';
			v[cnt][nextbi][nextbj] = '.';
			v[cnt][bi][bj] = 'B';
			v[cnt][ri][rj] = 'R';
			
		}		
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	v[0] = vector<string>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[0][i];
	}
	int ri, rj, bi, bj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[0][i][j] == 'R') {
				ri = i; rj = j;
			}
			else if (v[0][i][j] == 'B') {
				bi = i; bj = j;
			}
		}
	}
	f(1, ri, rj, bi, bj);	
	if (answer == 11) answer = -1;
	cout << answer;
	return 0;
}