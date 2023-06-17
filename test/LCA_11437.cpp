#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 배열의 인덱스를 각 노드의 키라고 할때 답을 삽입해 줌 현재 노드가 다음 노드의 부모임
// 부모 등록 할 때 뎁스도 같이 등록
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
    // 인풋이 부모에서 자식을 알려주니 반대로 자식에서 부모를 향하게 만들어 두고
    // 목표로 하는 노드들에서 부모로 가면서 방문여부를 체크하고 처음으로 발견한 방문노드가 공통 부모이다.
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

        // 둘 중 뎁스가 큰 녀석이 작은 녀석의 뎁스와 동일하도록 거슬러 올라감
        if (childToParent[a].second < childToParent[b].second) {
            b = goTo(childToParent, b, childToParent[a].second);
        }
        else {
            a = goTo(childToParent, a, childToParent[b].second);
        }
        
        // 공통 조상이 나올 때 까지 같이 거슬러 올라감
        while (a != b) {
            a = childToParent[a].first;
            b = childToParent[b].first;
        }

        cout << a << "\n";
    }

    return 0;
}