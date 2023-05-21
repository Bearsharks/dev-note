#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    if (k <= n) {
        // 수빈이가 동생보다 더 멀리 있다면 뒤로만 갈 수 있다.
        cout << n - k;
        return 0;
    }
    priority_queue<pair<int,int>> q;
    // 1 ~ 100001 까지 확보를 위함
    // 이렇게 하면 false로 전부 초기화가 됨
    bool isvisit[100002] = { false, };
    // 우선순위 큐는 기본이 오름차순 정렬이라 -를 줘서 따로 정렬 함수 안줘도 되게
    q.push({ 0, -n });
    isvisit[n] = true;
    int answer = 0;

    while (!q.empty()) {
        int time = -q.top().first;
        int x = -q.top().second;
        q.pop();
        
        if (x == k) {
            cout << time;
            return 0;
        }
        
        // k + 2 미만만 받아줌 -1 해서 갈 수 있게
        // 하나 뒤로가서 두 배 하는게 두배 한 다음 뒤로 두번가는 것보다는 빠름
        // 0일 때는 두배해도 0임
        if (x * 2 < k + 2 && !isvisit[x * 2]) {
            q.push({ -time, -2 *x });
            isvisit[2 * x] = true;
        }
        if (x + 1 < k + 2 && !isvisit[x + 1]) {
            q.push({ -(time + 1), -(x + 1) });
            isvisit[x + 1] = true;
        }
        if (x - 1 >= 0 && !isvisit[x - 1]) {
            q.push({ -(time + 1), -(x - 1) });
            isvisit[x - 1] = true;
        }
    }
    cout << k - n;
    return 0;
}