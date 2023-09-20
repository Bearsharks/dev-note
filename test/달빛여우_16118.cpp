#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
���� ����� �׳� ����
����� ���� Ȧ������ ¦�������� ���� ����.
���ͽ�Ʈ�󿡼� Ȧ¦ ������ ť�� �ְ� ���� �����ϸ� ��.
�׸��� ���� �� �׷��ͱ��� �Ÿ��� ���ؼ� �������� �� ª�� ���� ������ ����.
���ݼӵ��� ���� �Ҽ��� �����°� �Ⱦ �׳� ��� �� �� ������ ����� �׹�� �� �踸ŭ �� ��
�ʸ� * �ʸ� = 100�� �ι� �� ���̴� 200���̶� �Ҿ��ϱ� ������ Ʋ���� long long���� �ٲٰڴ�.
*/


/*
* Ʋ�� �� �׷��ͱ⿡ ���밡 �߽��� ���� �ƴѰ�� �Ѵ� ����� �ص־� �Ѵ� �ֳ��ϸ� �װ��� ���� ����� ������ ��ġ�⶧��
*/
vector<int> foxsp(vector<vector<pair<int, int>>> graph, int start) {
    vector<int> result(graph.size(), 2147483647);
    result[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int curidx = cur.second;
        if (cost > result[curidx]) continue;

        for (pair<int, int> adj : graph[curidx]) {
            if (result[adj.second] > cost + adj.first) {
                result[adj.second] = cost + adj.first;
                pq.push({ -(cost + adj.first), adj.second });
            }
        }
    }

    return result;
}

vector<vector<int>> wolfsp(vector<vector<pair<int, int>>> graph, int start) {
    vector<vector<int>> result(graph.size(), vector<int>(2, 2147483647));
    result[start][1] = 0;
    priority_queue<tuple<int, int, bool>> pq;
    pq.push({ 0,start, true});
    while (!pq.empty()) {
        tuple<int, int, bool> cur = pq.top();
        pq.pop();
        int cost = -get<0>(cur);
        int curidx = get<1>(cur);
        bool isFast = get<2>(cur);
        if (cost > result[curidx][isFast]) continue;

        for (pair<int, int> adj : graph[curidx]) {
            int nextCost = cost + (isFast ? adj.first / 2 : adj.first * 2);
            if (result[adj.second][!isFast] > nextCost) {
                result[adj.second][!isFast] = nextCost;
                pq.push({ -nextCost, adj.second, !isFast });
            }
        }
    }

    return result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        // �ι��ؾ� �Ҽ��� �ȳ���
        v[a].push_back({ c * 2, b });
        v[b].push_back({ c * 2, a });
    }
    vector<int> foxResult = foxsp(v, 1);
    vector<vector<int>> wolfResult = wolfsp(v, 1);
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += foxResult[i] < wolfResult[i][0] && foxResult[i] < wolfResult[i][1];
    }
    cout << result;
    return 0;
}
