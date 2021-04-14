#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int nv = 0, nh = 0;
    for (char c : s) {
        if (c == '0') {
            if (nv++) {
                cout << "1 4\n";                
                nv = 0;
            }
            else {
                cout << "3 4\n";
            }
        }
        else {
            if (nh++) {
                cout << "1 3\n";
                nh = 0;
            }
            else {
                cout << "1 1\n";
                
            }
        }
    }
    return 0;
}