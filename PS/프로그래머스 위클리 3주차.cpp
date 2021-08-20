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
//�ش� ���������� ��ǥ�� �ش� ������ ǥ���ϴ� key�� 4�� �����Ѵ�.(�� ȸ���� ����� 1���� Ű�� ǥ����)
vector<pair<int, int>> makeKeys(vector<pair<int, int>>& piece, int cnt = 4) {
    vector<pair<int, int>> keys;
    while (cnt--) {
        sort(piece.begin(), piece.end());
        pair<int, int> res = { 0,0 };
        //������ ã��
        int mnx = 100000, mny = 100000;
        for (int i = 0; i < piece.size(); i++) {
            mnx = min(piece[i].first, mnx);
            mny = min(piece[i].second, mny);
        }
        //Ű����
        int curdigit = 1;
        for (int i = 0; i < piece.size(); i++) {
            int x = piece[i].first - mnx;
            int y = piece[i].second - mny;
            res.first += x * curdigit;
            res.second += y * curdigit;
            curdigit *= 10;
        }
        keys.push_back(res);
        //90�� ������
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
    //�ʿ��� ������ ã�� ��Ͻ�Ŵ 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0) {
                vector<pair<int, int>> piece;
                dfs(game_board, i, j, 0, piece);
                vector<pair<int, int>> keys = makeKeys(piece);
                if (pieceMap.count(keys[0])) {
                    //�ش� ����� �����Ƿ� �� �������������� 1������Ŵ
                    int curPiece = pieceMap[keys[0]];
                    pieceCnt[curPiece]++;
                }
                else {
                    //�ش� ����� �����Ƿ� ���ο� ���������� �߰��ϰ� �� Ű�� ���ο� ���������� ���ν�Ŵ
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
    //���� �������� �ϳ��� ���簣��.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j]) {
                vector<pair<int, int>> piece;
                dfs(table, i, j, 1, piece);
                //�� ȸ���� ����� �տ��� �̹� ����߱� ������ Ű�� �ϳ��� �����Ѵ�.
                vector<pair<int, int>> keys = makeKeys(piece, 1);
                if (pieceMap.count(keys[0])) {//�ش� ������ �ʿ��ϸ�
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