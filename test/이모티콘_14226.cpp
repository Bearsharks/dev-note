#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

/*
�� Ƚ���� ���������� ���� 
�ٽ� ���� �� �̸�Ƽ�� ������ �ּ� ����Ƚ���� ���°� ���� dp�� ����� �����
100�� �̸�Ƽ�ܿ� Ŭ������ 2�� �� 100�� �̸�Ƽ�ܿ� Ŭ������ 100���� �ٸ�
���� ��ǥ������ �ּҸ� �˾Ƴ����ϸ� ��ǥ ���� - Ŭ������ ������ �Ѵ� ���� ��
������� 1000���� ��ǥ��  ����/Ŭ������� ������
999/1 998/2 997/3... �� ��� ���� �ּ� �Ǵ� ����
1000 * 1000 ���� ���¿��� 1000���� ���� �Ǵ� �����ϱ� ������ �ð���
1,000,000,000 10�� �ð� 5�� �ð�? �� ����

�ƴϸ� bfs�� �ּҰŸ� ���ϵ��� ���ϴ� ��
bfs�� ����, Ŭ������, Ƚ�� �ְ� ������
���� ������ Ƚ�� + ���� - ��ǥ

���� ���� Ƚ���� ������
�迭 �ϳ� ���
������ �ڵ� Ƚ�� ����ϰ� ����������
*/


unordered_set<int> prevSet = { 10001 };
unordered_set<int> already = { 10000, 0, 10001 };
int s;
int mn;

void insert(unordered_set<int>& set, int cnt, int val, int clip) {
    if (val < 1) return;
    int newone = val * 10000 + clip;
    if (already.count(newone)) return;
    if (val >= s) {
        int need = cnt + val - s;
        mn = min(need, mn);
    }
    set.insert(newone);
    already.insert(newone);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> s;

    mn = s;
    int cnt = 1;
    while (++cnt < mn) {
        unordered_set<int> set;
        for (int p : prevSet) {
            int val = p / 10000;
            int clip = p % 10000;
            insert(set, cnt, val, val);
            insert(set, cnt, val + clip, clip);
            insert(set, cnt, val - 1, clip);
        }
        prevSet = set;
    }

    cout << mn;
    return 0;
}
