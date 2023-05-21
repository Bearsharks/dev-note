#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    if (k <= n) {
        // �����̰� �������� �� �ָ� �ִٸ� �ڷθ� �� �� �ִ�.
        cout << n - k;
        return 0;
    }
    priority_queue<pair<int,int>> q;
    // 1 ~ 100001 ���� Ȯ���� ����
    // �̷��� �ϸ� false�� ���� �ʱ�ȭ�� ��
    bool isvisit[100002] = { false, };
    // �켱���� ť�� �⺻�� �������� �����̶� -�� �༭ ���� ���� �Լ� ���൵ �ǰ�
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
        
        // k + 2 �̸��� �޾��� -1 �ؼ� �� �� �ְ�
        // �ϳ� �ڷΰ��� �� �� �ϴ°� �ι� �� ���� �ڷ� �ι����� �ͺ��ٴ� ����
        // 0�� ���� �ι��ص� 0��
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