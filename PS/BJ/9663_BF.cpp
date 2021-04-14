#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int board[15] = { 0, };
int n;
int answer = 0;

bool cango(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < i; k++) {
        if (k == i || board[k] == j|| board[k] + (i - k) == j || board[k] - (i - k) == j) return false;
    }
    return true;
}

void f(int cnt) {
    if (cnt == n) {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cango(cnt, i)) {
            board[cnt] = i;
            f(cnt + 1);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    f(0);
    cout << answer;
    return 0;
}