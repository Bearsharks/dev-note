#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   int n;
    cin >> n;
    string s;
    cin >> s;
    
    int a = 1;
    for (; a < n; a++) {
        if (s.at(a) != s.at(a - 1)) break;
    }
    int b = 1;
    for (; b < n; b++) {
        if (s.at(n-b) != s.at(n - b - 1)) break;
    }
    
    if (s.at(0) == s.at(n - 1)) {
        cout << ((((long long)a + 1 % 998244353) * (b + 1 % 998244353) ) % 998244353) ;
    }
    else {
        cout << (((a  % 998244353) + (b % 998244353) + 1) % 998244353);
    }
    
    return 0;
}