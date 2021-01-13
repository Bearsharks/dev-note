#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    int a1 = 0, b1 = 0;
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }
    for (int i = 0,size = a.size(); i < size; i++) {
        a1 += a[i] - '0';
        b1 += b[i] - '0';
    }

    if( (a1 == 0 && b1 != 0) || (b1 == 0 && a1 != 0)) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}