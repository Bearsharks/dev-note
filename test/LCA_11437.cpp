#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// �迭�� �ε����� �� ����� Ű��� �Ҷ� ���� ������ �� ���� ��尡 ���� ����� �θ���
// �θ� ��� �� �� ������ ���� ���
void dfs(vector<vector<int>>& v, vector<pair<int,int>>& p, int cur, int depth) {
    for (int i : v[cur]) {
        if (p[i].first == 0) {
            p[i].first = cur;
            p[i].second = depth + 1;
            dfs(v, p, i, depth + 1);
        }
    }
}

int goTo(vector<pair<int, int>>& p, int idx, int depth) {
    int diff = p[idx].second - depth;
    while (diff--) {
        idx = p[idx].first;
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // ��ǲ�� �θ𿡼� �ڽ��� �˷��ִ� �ݴ�� �ڽĿ��� �θ� ���ϰ� ����� �ΰ�
    // ��ǥ�� �ϴ� ���鿡�� �θ�� ���鼭 �湮���θ� üũ�ϰ� ó������ �߰��� �湮��尡 ���� �θ��̴�.
    vector<vector<int>> v(n + 1);
    vector<pair<int, int>> childToParent(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }

    childToParent[1].first = -1;
    dfs(v, childToParent, 1, 0);
    childToParent[1].first = 0;
    int m;
    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        // �� �� ������ ū �༮�� ���� �༮�� ������ �����ϵ��� �Ž��� �ö�
        if (childToParent[a].second < childToParent[b].second) {
            b = goTo(childToParent, b, childToParent[a].second);
        }
        else {
            a = goTo(childToParent, a, childToParent[b].second);
        }
        
        // ���� ������ ���� �� ���� ���� �Ž��� �ö�
        while (a != b) {
            a = childToParent[a].first;
            b = childToParent[b].first;
        }

        cout << a << "\n";
    }

    return 0;
}