#include <iostream>
using namespace std;

/*
    각 행은 정렬되어있고,
    각 행에서 어떤 수 이하는 몇개인지 1시간에 알 수 있다.
    각 행은 최대 n이고
    n은 최대 10^5 개니까
    이분 탐색(어퍼바운드)으로 k번째 수를 찾는것은 
    log10^5 * n 시간이 든다.
*/

long long getRowCount(long long n, long long i, long long tgt) {
    return min(n, tgt / i);
}

long long getCount(long long n, long long tgt) {
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += getRowCount(n, i, tgt);
    }
    return result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;

    long long mn = 1, mx = n * n;
    while (mn < mx) {
        long long mid = (mx + mn) / 2;
        if (getCount(n, mid) >= k) {
            mx = mid;
        }
        else {
            mn = mid + 1;
        }
    }

    cout << mx;
    return 0;
}

/*
 틀림 10000 * 10000 이 mx 인데 int 범위 벗어남 ㅜㅜ
 
 */
