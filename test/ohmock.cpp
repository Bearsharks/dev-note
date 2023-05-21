#include <vector>
#include <iostream>
using namespace std;

pair<int, int> pos[] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0} };
vector<vector<int>> v(19, vector<int>(19));

bool isSame(int i, int j, int expect) {
    return i < 19 && i >= 0 && j < 19 && j >= 0 && v[i][j] == expect;
}

bool isWin(int i, int j) {
    int k = 4;
    while (k--) {
        if (isSame(i - pos[k].first, j - pos[k].second, v[i][j])) continue;
        if (isSame(i + 5 * pos[k].first, j + 5 * pos[k].second, v[i][j])) continue;
        int cnt = 1;
        for (int q = 1; q < 5; q++) {
            cnt += isSame(i + q * pos[k].first, j + q * pos[k].second, v[i][j]);
        }
        if (cnt == 5) return true;
    }
    return false;
}

pair<int, int> findWinnerPos() {
    pair<int, int> ret = {-1, -1};

    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (v[i][j] && isWin(i, j)) return {i, j};
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> v[i][j];
        }
    }

    pair<int, int> winner = findWinnerPos();
    if (winner.first != -1) {
        cout << v[winner.first][winner.second] << "\n";
        cout << winner.first + 1 << " " << winner.second + 1;
    }
    else {
        cout << 0;
    }
    return 0;
}