#include <iostream>
#include <vector>

using namespace std;

// 배열의 인덱스를 각 노드의 키라고 할때 답을 삽입해 줌 현재 노드가 다음 노드의 부모임
void dfs(vector<vector<int>>& v, vector<int>& answer, int cur) {
    for (int i : v[cur]) {
        if (answer[i] == -1) {
            answer[i] = cur;
            dfs(v, answer, i);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> answer(n+1,-1);
    answer[1] = 0;

    // 루트부터 자식을 순회하면서
    dfs(v, answer, 1);
    for (int i = 2; i <= n; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}