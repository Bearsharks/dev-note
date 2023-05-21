#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� ���� ������ ������ � ���� �ٸ� ���� ������ ��,
// ���ԵǴ� ���� �ڽ����� �ϴ� Ʈ����� ���� ��, �θ� �ڽİ����� �̵� �� �� �ְ�,
// ���� �� S�� �� �� E�� ���� �θ� P��� �ϸ� s -> p -> e ��θ� ����ϸ� �ȴ�.
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n = 0;
    int s, e;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int k, x, r;
        cin >> k >> x >> r;
        // ���ʰ� ������ ���� ��� �ص� �׸��� �� ���� ��� ���� ���ԵǴ��� ������ �� ������ ��� ����
        v.push_back({ x - r, k });
        v.push_back({ x + r, k });
    }
    cin >> s >> e;

    // ���� �����ϸ� �켱������ first���� �̹Ƿ� �� ���� �̷� ������� ���� �� ��-> ((()())(()))
    sort(v.begin(), v.end());

    vector<int> stack(0);
    vector<int> path1(0), path2(0);

    // ��Ʈ�� 0 ���� Ʈ�� ���� ���� 
    stack.push_back(0);
    // ((()())(()) �̰� ��ȸ �� �� 
    for (int i = 0; i < 2 * n; i++) {
        //���� ž�� �ִ� ���� ���� ���� �θ� ��
        int prev = stack.back();
        int cur = v[i].second;
        stack.push_back(cur);

        if (prev == cur) {
            // ���� ž�� ���� ���� ���� ������ () �̷� ���´ϱ� ���ÿ��� ������
            stack.pop_back();
            if (cur == s) {
                // ���� ���� ���� �� �̶�� ���� ���ÿ� ����ִ� ���� ��Ʈ���� ���� �� ������ ���
                path1 = stack;
            }
            else if (cur == e) {
                // ���� ���� �� �� �̶�� ���� ���ÿ� ����ִ� ���� ��Ʈ���� �� �� ������ ���
                path2 = stack;
            }
            stack.pop_back();
        }
    }

    int sameParent;
    for (int i = 0; path1[i] == path2[i]; i++) {
        sameParent = i;
    }

    // ���ۿ����� ����θ� �������� �Ÿ� + ���� �θ𿡼� ���������� �Ÿ� = ��ü �̵� �Ÿ�
    cout << path1.size() - sameParent + path2.size() - sameParent - 1 << "\n";
    for (int i = path1.size() - 1; i > sameParent; i--) {
        cout << path1[i] << " ";
    }

    // ��� �� " "�� �������� ���� ���� �����ϱ� ���� ù��°�� �̸� �����
    cout << path1[sameParent];
    for (int i = sameParent + 1; i < path2.size(); i++) {
        cout << " " << path2[i];
    }
    return 0;
}
