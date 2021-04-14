#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool isNG = n > m;
    if (isNG) {
        swap(n, m);
    }
    cout << n + 1 << "\n";

    vector<pair<int, int>> ans;
    for (int i = 0; i <= n; i++) {
        ans.push_back({ i,m-- });
    }

    if (isNG) {
        for (pair<int, int> p : ans) {
            cout << p.second << " " << p.first << "\n";
        }
    }
    else {
        for (pair<int, int> p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}