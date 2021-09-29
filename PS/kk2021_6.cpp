#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<vector<int>> board;
vector<vector<int>> isVisit;
vector<vector<pair<int, int>>> tilePos(7);
int n;
inline int getDist(pair<int, int> s, pair<int, int> dest) {
    return abs(s.first - dest.first) + abs(s.second - dest.second);
}
pair<int, int> getCntMovePos(int direcIdx, pair<int,int> curPos) {
    int dR = d[direcIdx].first;
    int dC = d[direcIdx].second;
    int curR = curPos.first;
    int curC = curPos.second;
    while (0 <= dR + curR && dR + curR < 4
            && 0 <= dC + curC && dC + curC < 4) {
        curR += dR;
        curC += dC;
        if (board[curR][curC]) break;
    }
    return { curR,curC };
}

int getMinCost(pair<int,int> s, pair<int,int> dest, int limit) {
    int result = getDist(s,dest);
    if (abs(s.first - dest.first) <= 1 && abs(s.second - dest.second) <= 1)
        return result;
    if (limit == 0) return 123456789;
    for (int i = 0; i < 4; i++) {
        int nextr = d[i].first + s.first;
        int nextc = d[i].second + s.second;
        if (0 <= nextr && nextr < 4 && 0 <= nextc && nextc < 4) {
            result = min(getMinCost({ nextr,nextc }, dest, limit - 1) + 1, result);
        }
    }
    for (int i = 0; i < 4; i++) {
        pair<int, int> next = getCntMovePos(i, s);
        int nextr = next.first;
        int nextc = next.second;
        if (getDist(next,s) >= 2) {
            int newLimit = getDist(next, dest);
            result = min(getMinCost({ nextr,nextc }, dest, min(limit - 1, newLimit)) + 1, result);
        }            
    }
    return result;
}
int dfs(pair<int,int> curPos, int remain) {
    if (remain == 0) return 0;
    int answer = 987654321;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) {
                int cur = board[i][j];
                pair<int, int> one = tilePos[cur][0];
                pair<int, int> two = tilePos[cur][1];
                if (one.first != i || one.second != j) swap(one, two);
                int cost = getMinCost(curPos, one, getDist(curPos, one)) + 1 + getMinCost(one, two, getDist(one, two)) + 1;
                board[one.first][one.second] = 0;
                board[two.first][two.second] = 0;
                answer = min(answer, cost + dfs(two,remain-1));
                board[one.first][one.second] = cur;
                board[two.first][two.second] = cur;
            }
        }
    }
    return answer;
}
int solution(vector<vector<int>> board_, int r, int c) {
    
    //핵심은 제일 먼저 제거할 타일을 선택하는 것
    //어떤 위치에서 다른 위치로 가는 횟수를 계산하는 함수가 있다면
    board = board_;
    set<int> s;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            s.insert(board[i][j]);
            tilePos[board[i][j]].push_back({ i,j });
        }
    }
    
    int answer = dfs({ r,c },s.size()-1);
    return answer;
}

int main() {
    vector<vector<int>> board = {{3,0,0,2}, {0,0,1,0}, {0,1,0,0}, {2,0,0,3}};
    solution(board, 1, 0);
    return 0;
}