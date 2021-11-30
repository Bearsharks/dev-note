#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    lis.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        auto iter = upper_bound(lis.begin(), lis.end(), v[i]);
        if (iter == lis.end()) lis.push_back(v[i]);
        else *iter = v[i];
    }
    cout << n - lis.size();
    return 0;
}