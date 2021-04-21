#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v(n);
    long long answer[3];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long curmn = 9876543211;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            long long candi = v[i] + v[l] + v[r];
            if (curmn > abs(candi)) {
                curmn = abs(candi);
                answer[0] = v[i];
                answer[1] = v[l];
                answer[2] = v[r];
            }
            if (candi > 0) {
                r--;
            }
            else {
                l++;
            }
        }
    }
    cout << answer[0] << " " << answer[1] << " " << answer[2];
    return 0;
}
