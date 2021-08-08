#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;


int isErasable(vector<vector<int>>& board, int i, int j) {
    int cur = board[i][j];
    if (i + 2 < board.size() && board[i + 2][j] == cur) {//아래로 세칸
        if (j + 1 < board.size() && board[i + 2][j+1] == cur) {
            return 1;//L모양
        }
        else if (j - 1 >= 0 && board[i + 2][j - 1] == cur){
            return 2;//_| 모양
        }
    }
    else if(board[i + 1][j] == cur){
        if (j + 2 < board.size() && board[i + 1][j + 2] == cur) {
            return 3;//|__모양
        }
        else if (j - 2 >= 0 && board[i + 1][j - 2] == cur) {
            return 4;//__|모양
        }
        else if (j + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == cur && board[i + 1][j + 1] == cur) {
            return 5; //ㅗ모양
        }
    }
    return 0;
}
vector<pair<int, int>> needCol = { {0,0}, {1,1}, {-1,-1}, {1,2}, {-1,-2}, {-1,1} };

vector<pair<int, int>> d = {{ -1,0 }, { 0,1 }, { 1,0 }, { 0,-1 }};
void marking(vector<vector<int>>& board, int i, int j, int mark, set<int>& markedCol) {
    markedCol.insert(j);
    int cur = board[i][j];
    board[i][j] = mark;
    for (int k = 0; k < 4; k++) {
        int nexti = i + d[k].first;
        int nextj = j + d[k].second;
        if (nexti >= 0 && nexti < board.size() && nextj >= 0 && nextj < board.size() &&
            board[nexti][nextj] == cur) {
            marking(board, nexti, nextj, mark, markedCol);
        }
    }
}
int solution(vector<vector<int>> board) {
    for (vector<int> v : board) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    int answer = 0;
    int n = board.size();
    set<int> markedCol;
    set<int> isvisit;
    vector<vector<tuple<int, int, int>>> reserve(board.size());
    //좌상부터 우하까지 블록 있으면 되는 모양인지 체크
    for (int i = 0; i < n; i++) {
        //행 시작할 때 체크하라고 등록한 녀석들이 현재 안되는 곳을 고려해도 지워질 수 있는지 확인
        for (tuple<int, int, int>&  t : reserve[i]) {
            //지워질 수 있으면 지움
            //못지우면 안되는곳이라고 등록함
            int row = get<0>(t); int col = get<1>(t); int kind = get<2>(t);
            bool notErasable = markedCol.count(col + needCol[kind].first) || markedCol.count(col + needCol[kind].second);
            
            cout << row << " " << col << "\n";
            if (notErasable) {
                marking(board, row, col, 0, markedCol);
            }
            else {
                answer++;
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (board[i][j] && isvisit.count(board[i][j]) == 0) {
                isvisit.insert(board[i][j]);
                int res = isErasable(board, i, j);
                if (res == 0) {
                    //안되는 모양이면 차지하는 열들에 안되는 곳이라고 등록
                    marking(board, i, j, 0, markedCol);
                }
                else {
                    //되는 모양이면 제일 아래 행이 시작할 때 체크하도록 등록                    
                    if (res < 3) {
                        reserve[i + 2].push_back({ i, j, res });
                    }
                    else {
                        reserve[i + 1].push_back({ i, j, res });
                    }
                }
            }
        }
    }
    
    
    
    return answer;
}

int main() {
    cout << solution({{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 4, 4, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5}, {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}});
    return 0;
}