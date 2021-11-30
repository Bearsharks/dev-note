#include <vector>
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);        
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> answer(n);
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (v[i] * sum > 0 ) {
                sum -= v[i];
                answer[i] = -1;
            }
            else {
                sum += v[i];
                answer[i] = 1;
            }
        }
        if (sum == 0) {
            sum += v[n - 1] * answer[n - 1];
            answer[n - 1] *= 2;
        }
        cout << -sum;
        for (int i = 1; i < n; ++i) {
             cout << " " << answer[i] * v[0];   
        }
        cout << "\n";
    }    
    return 0;
}