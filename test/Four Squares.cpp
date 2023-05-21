#include <vector>
#include <iostream>
using namespace std;

int n;
int mn = 4;
void findlg(int cur, int sum, int cnt) {
    if (sum == n) {
        mn = mn < cnt ? mn : cnt;
        return;
    }
    if (cnt >= mn || cur* cur + sum > n) return;
    findlg(cur + 1, sum, cnt);
    findlg(cur, sum + cur * cur, cnt + 1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    findlg(1, 0, 0);
    cout << mn;
    return 0;
}