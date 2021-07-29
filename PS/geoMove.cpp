#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;

/*
void grouping(vector<vector<pair<int, int>>>& landInfo, int height, int i, int j,int groupId) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    landInfo[i][j].second = groupId;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nexti = i + dy[k];
            int nextj = j + dx[k];
            if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < N &&
                landInfo[nexti][nextj].second == -1 &&
                abs(landInfo[nexti][nextj].first - landInfo[i][j].first) <= height)
            {
                landInfo[nexti][nextj].second = groupId;
                q.push({ nexti,nextj });
            }
        }
    }
}
*/

class DSU {
public:
    DSU() {
    }
    DSU(int n) :parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return v;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
        return v;
    }
    void makeSet() {
        int i = parent.size();
        parent.push_back(i);
        rank.push_back(1);
    }
private:
    vector<int> parent;
    vector<int> rank;
};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int N = land.size();
    vector < vector<pair<int, int>>> landInfo(N, vector<pair<int, int>>(N));

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            landInfo[i][j].first = land[i][j];
            landInfo[i][j].second = cnt++;
        }
    }
    //� ĭ���� �ٸ� ĭ���� �� �� ���̰� �Ǹ� �����ϰ� �ȵǸ� ��ٸ� ��µ� �󸶰� ������� {���, �׷��̸�}���� �迭�� �ִ´�.
    //��� ĭ�����ؼ� �ݺ��Ѵ�.
    vector<tuple<int, int, int>> testV;
    DSU dsu(cnt);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int nexti = i ;
            int nextj = j + 1;
            if (nexti < N && nextj < N){
                int dh = abs(landInfo[nexti][nextj].first - landInfo[i][j].first);
                if (dh <= height) {
                    dsu.merge(landInfo[i][j].second, landInfo[nexti][nextj].second);
                }
                else {
                    testV.push_back({ dh, landInfo[i][j].second, landInfo[nexti][nextj].second });
                }
            }

            nexti = i + 1;
            nextj = j;
            if (nexti < N && nextj < N) {
                int dh = abs(landInfo[nexti][nextj].first - landInfo[i][j].first);
                if (dh <= height) {
                    dsu.merge(landInfo[i][j].second, landInfo[nexti][nextj].second);
                }
                else {
                    testV.push_back({ dh, landInfo[i][j].second, landInfo[nexti][nextj].second });
                }
            }
        }
    }
    //��� ������ �����Ѵ�.
    sort(testV.begin(), testV.end());
    
    //���� ���� ����� ���յ� �׷��̸� �Ѿ��.
    //���յ��� ���� �׷��̸� �����ϰ� �信 ���ϰ� ���յǾ��ٰ� ǥ���Ѵ�. set
    //������ �ݺ��Ѵ�.
    for (tuple<int, int, int>& tu : testV) {
        if (dsu.find(get<1>(tu)) == dsu.find(get<2>(tu))) continue;

        answer += get<0>(tu);
        dsu.merge(get<1>(tu), get<2>(tu));
    }
    return answer;
}

int main() {
    cout << solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1);
    return 0;
}