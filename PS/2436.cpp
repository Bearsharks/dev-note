


#include <iostream>
#include <cmath>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int answer;
    for (int i = sqrt(b / a); i >= 1; i--) {
        if ((b / a) % i == 0) {
            int one = i;
            int two = b / (i * a);
            bool isGood = true;
            for (int k = 2; k < one; k++) {
                if (one % k == 0 && two % k == 0) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) {
                cout << one * a << " " << two * a;
                return 0;
            }
        }
    }
    return 0;
}