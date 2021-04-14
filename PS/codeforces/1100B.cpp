#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> pool(n+1);
    vector<int> round(m+1);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        pool[a]++;
        round[pool[a]]++;
        if (round[pool[a]] >= n) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    return 0;
}