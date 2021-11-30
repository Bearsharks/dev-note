#include <vector>
#include <iostream>

using namespace std;

int table[129][129] = { 0, };
//Èò, ÆÄ
pair<int, int> recur(int u, int l, int d, int r) {
    if (u == d) return { !table[u][l], table[u][l] };
    pair<int, int> ul = recur(u, l, (u + d) / 2, (l + r) / 2);
    pair<int, int> ur = recur(u, (l + r) / 2 + 1, (u + d) / 2, r);
    pair<int, int> dl = recur((u + d) / 2 + 1, l, d, (l + r) / 2);
    pair<int, int> dr = recur((u + d) / 2 + 1, (l + r) / 2 + 1, d, r);
    if (ul == ur && ur == dl && dl == dr && ul.first + ul.second == 1)  {
        return ul;
    }
    return { ul.first+ur.first+dl.first+dr.first, ul.second + ur.second + dl.second + dr.second };
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    pair<int, int> answer = recur(0, 0, n - 1, n - 1);
    cout << answer.first << "\n" << answer.second;
    return 0;
}