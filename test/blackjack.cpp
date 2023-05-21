#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<int> v;

int findMax(int idx, int sum, int remain) {
    if (remain == 0) {
        if (sum > m) return -876543210;
        return sum;
    }
    if (idx >= n) return -876543210;
    int candi1 = findMax(idx + 1, sum + v[idx], remain - 1);
    int candi2 = findMax(idx + 1, sum, remain);
    return candi1 > candi2 ? candi1 : candi2;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    v.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << findMax(0, 0, 3);

    return 0;
}