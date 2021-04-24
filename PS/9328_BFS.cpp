#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

pair<int, int> D[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int n, m;
void pushAccessibleFrom(pair<int, int> cur, queue<pair<int, int>>& q, vector<string>& board) {
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + D[i].first;
		int nexty = cur.second + D[i].second;
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
			q.push({ nextx,nexty });
		}		
	}
}
bool isAccessble(pair<int, int> cur, vector<string>& board) {
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + D[i].first;
		int nexty = cur.second + D[i].second;
		if(board[nextx][nexty] == '`') return true;
	}
	return false;
}
//현재 갈 수 있는 곳에 다 가본 뒤에 이때까지 찾은 문서갯수와 키를 돌려준다
int findAccessibleArea(queue<pair<int, int>>& q, vector<string>& board, set<char>& keys) {
	int ret = 0;
	while (q.size()) {
		pair<int, int> cur = q.front(); q.pop();
		if (board[cur.first][cur.second] == '.') {
			;
		}
		else if ('a' <= board[cur.first][cur.second] && board[cur.first][cur.second] <= 'z') {
			keys.insert(board[cur.first][cur.second]);
		}
		else if (board[cur.first][cur.second] == '$') {
			ret++;
		}
		else {
			continue;
		}
		board[cur.first][cur.second] = '`';
		pushAccessibleFrom(cur, q, board);		
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {		
		cin >> n >> m;
		n += 2;
		m += 2;
		vector<string> board(n);
		stringstream ss;
		for (int j = 0; j < m + 2; j++) {
			ss << '.';
		}			
		string ppp;
		ss >> ppp;
		board[0] = ppp; board[n - 1] = ppp;
		for (int i = 1; i < n-1; i++){
			cin >> board[i];
			board[i] = '.' + board[i] + '.';
		}
		string k;
		cin >> k;
		set<char> keys;
		if (k != "0") {
			for (char key : k) {
				keys.insert(key);
			}
		}
		
		//문 위치를 등록함
		vector<vector<pair<int, int>>> doors(26);
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if ('A' <= board[i][j] && board[i][j] <= 'Z'){
					doors[board[i][j] - 'A'].push_back({ i,j });
				}
			}
		}
		//초기 큐, 키세팅
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		int answer = 0;
		while (keys.size() + q.size()) {
			for (char k : keys) {
				//현재 가진 키로 문 다열고
				for (pair<int, int> doorpos : doors[k - 'a']) {
					board[doorpos.first][doorpos.second] = '.';
					//갈 수 있는 문이면 큐에 추가함.
					if (isAccessble({ doorpos.first, doorpos.second }, board)) {
						q.push({ doorpos.first, doorpos.second });
					}					
				}
				//열린 문을 지운다.
				doors[k - 'a'].clear();
			}			
			//사용한 열쇠를 버리기
			keys.clear();
			answer += findAccessibleArea(q, board, keys);
		}
		cout << answer << "\n";
	}
	
	return 0;
}