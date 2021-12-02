#include <iostream>
#include <vector>
using namespace std;

class lcr{
public:
    int l = 0, c = 0, r = 0;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int map[1001][1001];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i < m; i++) {
        map[0][i] += map[0][i-1];
    }
    for (int i = 1; i < n; i++) {
        vector<int> test1(m);
        test1[0] = map[i][0] + map[i - 1][0];
        for (int j = 1; j < m; j++) {
            test1[j] = max(test1[j - 1], map[i - 1][j]) + map[i][j];
        }
        vector<int> test2(m);
        test2[m - 1] = map[i][m - 1] + map[i - 1][m - 1];
        for (int j = m-2; j >= 0; j--) {
            test2[j] = max(test2[j + 1], map[i - 1][j]) + map[i][j];
        }
        for (int j = 0; j < m; j++) {
            map[i][j] = max(test1[j] , test2[j]);
        }
    }
    cout << map[n - 1][m - 1];

    return 0;
}