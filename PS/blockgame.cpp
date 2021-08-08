#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;


int isErasable(vector<vector<int>>& board, int i, int j) {
    int cur = board[i][j];
    if (i + 2 < board.size() && board[i + 2][j] == cur) {//�Ʒ��� ��ĭ
        if (j + 1 < board.size() && board[i + 2][j+1] == cur) {
            return 1;//L���
        }
        else if (j - 1 >= 0 && board[i + 2][j - 1] == cur){
            return 2;//_| ���
        }
    }
    else if(board[i + 1][j] == cur){
        if (j + 2 < board.size() && board[i + 1][j + 2] == cur) {
            return 3;//|__���
        }
        else if (j - 2 >= 0 && board[i + 1][j - 2] == cur) {
            return 4;//__|���
        }
        else if (j + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == cur && board[i + 1][j + 1] == cur) {
            return 5; //�Ǹ��
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
    //�»���� ���ϱ��� ��� ������ �Ǵ� ������� üũ
    for (int i = 0; i < n; i++) {
        //�� ������ �� üũ�϶�� ����� �༮���� ���� �ȵǴ� ���� ����ص� ������ �� �ִ��� Ȯ��
        for (tuple<int, int, int>&  t : reserve[i]) {
            //������ �� ������ ����
            //������� �ȵǴ°��̶�� �����
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
                    //�ȵǴ� ����̸� �����ϴ� ���鿡 �ȵǴ� ���̶�� ���
                    marking(board, i, j, 0, markedCol);
                }
                else {
                    //�Ǵ� ����̸� ���� �Ʒ� ���� ������ �� üũ�ϵ��� ���                    
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