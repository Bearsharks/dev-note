#include <vector>
#include <iostream>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m ,k;
    cin >> n >> m >>k;

    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        v[i] = v[i - 1] + a;
    }
    for(int i = 0 ; i< m;)
    return 0;
}