#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(4, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[j][i];
        }
    }

    vector<int> ab;
    vector<int> cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(-(v[0][i] + v[1][j]));
            cd.push_back(v[2][i] + v[3][j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    unsigned long long answer = 0;

    int prevab = -2147483647;
    int prevcnt = 0;
    vector<int>::iterator begin = cd.begin();
    for (int i = 0, last = ab.size(); i < last; i++) {
        if (ab[i] == prevab) {
            answer += prevcnt;
        }
        else {
            begin = lower_bound(begin, cd.end(), ab[i]);
            int cnt = 0;
            while (begin != cd.end() && *begin == ab[i]) {
                cnt++;
                begin++;
            }
            answer += cnt;
            prevcnt = cnt;
            prevab = ab[i];
        }
    }
    cout << answer;

    return 0;
}