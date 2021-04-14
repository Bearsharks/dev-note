#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    if (n < k * 3) {
        cout << -1;
        return 0;
    }

    int curk = 0;
    int i = 1;
    for (; i < 2*k;i+=2) {
        cout << curk+1 << " " << curk+1 << " ";
        curk++;
    }
    
    for (; i <= n; i++) {
        curk %= k;
        cout << curk + 1 << " ";
        curk++;
    }

    return 0;
}