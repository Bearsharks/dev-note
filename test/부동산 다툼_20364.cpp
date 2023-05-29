#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // ���� �� Ʈ����. �迭�� ǥ������
    // ���ϴ� ������ ���� 2�� �����鼭 0���� ���鼭,
    // ����ġ�� ������ ������ �� ������ ������Ʈ ��Ų��.
    // ������ ���� �����ٸ� �� ������ set�� �ΰ� ��ȸ �� hash_set�� ���� �ð��� ��� �ð����� ã�� �� �ִ�.
    // ��ȣ�� 2 ^ 20�� ��ŭ ������ ã�� �ִ�ð��� 20, ���� �� 20�� 20 * 20�� = 400�� �̴ϱ� ����

    unordered_set<int> happyOris;
    for (int i = 0; i < m; i++) {
        int ori;
        cin >> ori;
        int cur = ori;

        int lastHappyOri = 0;
        while (cur > 0) {
            if (happyOris.count(cur)) {
                lastHappyOri = cur;
            }
            cur /= 2;
        }
        if (lastHappyOri == 0) happyOris.insert(ori);
        cout << lastHappyOri << "\n";
    }
    return 0;
}