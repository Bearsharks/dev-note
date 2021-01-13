#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    int total = 0;
    stringstream ans;
    for (int i = 0; i < n; i++) {
        int a, g;
        cin >> a >> g;
        if (-500 <= total + a && total + a <= 500) {
            ans << "A";
            total += a;
        }
        else {
            ans << "G";
            total -= g;
        }
    }
    cout << ans.str();
    return 0;
}