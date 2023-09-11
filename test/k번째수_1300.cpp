#include <iostream>
using namespace std;

/*
    �� ���� ���ĵǾ��ְ�,
    �� �࿡�� � �� ���ϴ� ����� 1�ð��� �� �� �ִ�.
    �� ���� �ִ� n�̰�
    n�� �ִ� 10^5 ���ϱ�
    �̺� Ž��(���۹ٿ��)���� k��° ���� ã�°��� 
    log10^5 * n �ð��� ���.
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
 Ʋ�� 10000 * 10000 �� mx �ε� int ���� ��� �̤�
 
 */
