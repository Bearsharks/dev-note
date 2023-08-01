#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

/*
    1. ����
    ��� ���� �ִ� ���� ���ӵ� �ʹ信�� ������ ���� �� ���� ������ �����ʹ��� ���ԵǾ��ִ����̴�.
    ���� ���ļ� ���� ������ �ʹ��� ������ ������ ���� �� �ִ�.
    ������ ���� �տ��� ���� �ڱ��� �� �о�鼭 �� ���� �ִ� ���� ���ϸ� �� ��.
    ���۰� ���� �����͸� �����ϸ鼭 ���ۿ��� ����� ���տ��� ���� ������ ���ԵǸ� ���տ� �߰� �ϸ鼭
    ��� ������ ������. (���� ť�� �ٲ�)
    ������ �ؽø����� �ΰ�, �ؽø��� ������ ������ �����ϰ� ����.
    �̷� Ǯ���� �ð� ���⵵�� ����ϸ� �ؽø� ��ȸ �߰�, ������ ����ð� �տ��� �߰��ϰ� ���� �� ����ð�
    �׷��� �ð� ���⵵�� n�̴�.
*/

int oneAddAndOneOut(int a, int c, queue<int>& q, unordered_map<int,int>& qinfo) {
    q.push(a);
    qinfo[a]++;

    // ó�� �ʹ� ����
    int front = q.front();
    q.pop();
    int cnt = --qinfo[front];
    if (cnt == 0) qinfo.erase(front);
    int bonus = !qinfo.count(c);
    return bonus + qinfo.size();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    queue<int> q;
    unordered_map<int, int> qinfo;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        q.push(a);
        qinfo[a]++;
        v.push_back(a);
    }

    int answer = !qinfo.count(c) + qinfo.size();
    if (answer >= k + 1) {
        cout << answer;
        return 0;
    }
    for (int i = k; i < n; i++) {
        // ���� �ʹ� �߰�
        int a;
        cin >> a;
        int cnt = oneAddAndOneOut(a, c, q, qinfo);
        answer = answer > cnt ? answer : cnt;
        if (answer >= k + 1) {
            cout << answer;
            return 0;
        }
    }

    for (int i = 0; i < k - 1; i++) {
        int cnt = oneAddAndOneOut(v[i], c, q, qinfo);
        answer = answer > cnt ? answer : cnt;
        if (answer >= k + 1) {
            cout << answer;
            return 0;
        }
    }

    cout << answer;
    return 0;
}
// Ʋ�� �ֳ��ϸ� ȸ���ʹ��̱⶧�� ��ó���� �����صΰ� ������ �������� ������.