#include <iostream>
#include <string>
#include <vector>

using namespace std;

const pair<int, int> D[4] = { {-1,0},{0,1},{1,0},{0,-1}};
int dp[2][25][25];
int n;
vector<vector<int>>* b;

void dfs(pair<int, int> cur, int curCost, int state) {      
    if (cur.first == n - 1 && cur.second == n - 1) return;

    for (int i = 0; i < 4; i++) {
        int nexti = cur.first + D[i].first;
        int nextj = cur.second + D[i].second;
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && (*b)[nexti][nextj] == 0) {
            int nextState = (i % 2) + 1;
            bool isStateChange = (nextState & state) == 0;
            int nextCost = curCost + 100 + isStateChange * 500;
            if (dp[nextState - 1][nexti][nextj] > nextCost) {
                dp[nextState - 1][nexti][nextj] = nextCost;
                dfs({ nexti,nextj }, nextCost, nextState);
            }                
        }
    }
}

int solution(vector<vector<int>> board) {
    b = &board;
    n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) {
            dp[0][i][j] = 987654321;
            dp[1][i][j] = 987654321;
        }
    }
    dp[1][0][0] = 0;
    dp[0][0][0] = 0;
    dfs({ 0,0 }, 0, 3);
    return min(dp[0][n-1][n-1], dp[1][n-1][n-1]);
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //vector<vector<int>> board = { {0, 0, 0}, { 0, 0, 0 }, {0, 0, 0} };
    vector<vector<int>> board = { {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0} };
    cout << solution(board);
	return 0;
}