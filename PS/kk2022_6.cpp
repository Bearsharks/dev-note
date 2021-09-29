
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    int s = skill.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int health = board[i][j];
            for (int k = 0; k < s; k++) {
                int isAttack = (skill[k][0] == 1);
                int u = skill[k][1], l = skill[k][2], d = skill[k][3], r = skill[k][4];
                int degree = skill[k][5];
                if (isAttack) degree *= -1;
                if (u <= i && i <= d && l <= j && j <= r) {
                    health += degree;
                }                
            }
            if (health > 0) answer++;
        }
    }
    return answer;
}

int aamain() {
    solution({ {5,5,5,5,5} ,{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5} }, {{1, 0, 0, 3, 4, 4}, {1, 2, 0, 2, 3, 2}, {2, 1, 0, 3, 1, 2}, {1, 0, 1, 3, 3, 1}} );
    return 0;
}