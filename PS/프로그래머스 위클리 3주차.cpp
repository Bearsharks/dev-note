#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };
void dfs(vector<vector<int>>& board, int i, int j, int kind, vector<pair<int, int>>& piece) {
    board[i][j] = !kind;
    piece.push_back({ i,j });
    for (int k = 0; k < 4; k++) {
        int nexti = d[k].first + i;
        int nextj = d[k].second + j;
        if (0 <= nexti && nexti < n && 0 <= nextj && nextj < n && board[nexti][nextj] == kind) {
            dfs(board, nexti, nextj, kind, piece);
        }
    }
}
//해당 퍼즐조각의 좌표로 해당 조각을 표현하는 key를 4개 생성한다.(각 회전별 모양이 1개의 키로 표현됨)
vector<pair<int, int>> makeKeys(vector<pair<int, int>>& piece, int cnt = 4) {
    vector<pair<int, int>> keys;
    while (cnt--) {
        sort(piece.begin(), piece.end());
        pair<int, int> res = { 0,0 };
        //기준점 찾기
        int mnx = 100000, mny = 100000;
        for (int i = 0; i < piece.size(); i++) {
            mnx = min(piece[i].first, mnx);
            mny = min(piece[i].second, mny);
        }
        //키생성
        int curdigit = 1;
        for (int i = 0; i < piece.size(); i++) {
            int x = piece[i].first - mnx;
            int y = piece[i].second - mny;
            res.first += x * curdigit;
            res.second += y * curdigit;
            curdigit *= 10;
        }
        keys.push_back(res);
        //90도 돌리기
        for (int i = 0; i < piece.size(); i++) {
            int x = piece[i].first;
            int y = piece[i].second;
            piece[i] = { y,piece.size() - 1 - x };
        }
    }
    return keys;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    vector<int> pieceCnt;
    vector<int> numOfBlockOfPiece;
    map<pair<int, int>, int> pieceMap;
    int answer = 0;
    //필요한 조각를 찾아 등록시킴 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0) {
                vector<pair<int, int>> piece;
                dfs(game_board, i, j, 0, piece);
                vector<pair<int, int>> keys = makeKeys(piece);
                if (pieceMap.count(keys[0])) {
                    //해당 모양이 있으므로 그 퍼즐조각갯수를 1증가시킴
                    int curPiece = pieceMap[keys[0]];
                    pieceCnt[curPiece]++;
                }
                else {
                    //해당 모양이 없으므로 새로운 퍼즐조각를 추가하고 각 키에 새로운 퍼즐조각을 맵핑시킴
                    int curPiece = pieceCnt.size(); 
                    pieceCnt.push_back(1); 
                    numOfBlockOfPiece.push_back(piece.size());
                    for (pair<int, int> key : keys) {
                        pieceMap[key] = curPiece;
                    }
                }
            }
        }
    }
    //가진 조각들을 하나씩 맞춰간다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j]) {
                vector<pair<int, int>> piece;
                dfs(table, i, j, 1, piece);
                //각 회전된 모양을 앞에서 이미 등록했기 때문에 키를 하나만 생성한다.
                vector<pair<int, int>> keys = makeKeys(piece, 1);
                if (pieceMap.count(keys[0])) {//해당 조각이 필요하면
                    int curPiece = pieceMap[keys[0]];
                    if (pieceCnt[curPiece]) {
                        pieceCnt[curPiece]--;
                        answer += numOfBlockOfPiece[curPiece];
                    }
                }
            }
        }
    }
    return answer;
}

int main() {
    cout << solution({{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}},
        {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}} );
    return 0;
}