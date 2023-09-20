#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
전략 여우는 그냥 가고
늑대는 현재 홀수인지 짝수인지를 보고 간다.
다익스트라에서 홀짝 정보를 큐에 넣고 같이 생각하면 됨.
그리고 나온 각 그루터기의 거리를 비교해서 여우쪽이 더 짧은 곳의 갯수를 센다.
절반속도로 갈때 소수점 나오는게 싫어서 그냥 모두 두 배 때리고 늑대는 네배와 한 배만큼 갈 것
십만 * 십만 = 100억 두배 할 것이니 200억이라 불안하긴 하지만 틀리면 long long으로 바꾸겠다.
*/


/*
* 틀림 각 그루터기에 늑대가 쌩쌩한 경우랑 아닌경우 둘다 기록을 해둬야 한다 왜냐하면 그것이 다음 결과에 영향을 미치기때문
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
        // 두배해야 소수점 안나옴
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
