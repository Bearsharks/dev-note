#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m , k;
    cin >> n >> m >> k;
    vector<int> v;

    int first;
    cin >> first;
    int prev = first;    
    int cur = first;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        v.push_back(cur - prev -1);
        prev = cur;
    }
    sort(v.begin(), v.end());

    long long ans = (long long)cur - first + 1;
    for (int i = 0; i < k - 1; i++) {
        ans -= v[n-2-i];
    }
    cout << ans;


    return 0;
}