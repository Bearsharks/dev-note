#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
public:
    DSU() {
    }
    DSU(int n) :parent(n), rank(n, 1), size(n, 1) {
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
        size[v] += size[u];
        if (rank[u] == rank[v]) rank[v]++;
        return v;
    }
    void makeSet() {
        int i = parent.size();
        parent.push_back(i);
        rank.push_back(1);
        size.push_back(1);
    }
    int getSize(int u) {
        return size[find(u)];
    }
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};

class DsuNode{
public:
    DsuNode() {}
    DsuNode(int i, int left, int right) : index(i), l(left), r(right) { }
    int index;
    int l;
    int r;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,match;
    cin >> n>> match;
    vector<int> ans(n);
    unordered_map<int, DsuNode> m;
    //dsu 초기화하기
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        m.insert({ i, DsuNode(i, i, i) });
    }

    while (match--) {
        int l, r, winner;
        cin >> l >> r >> winner;
        l--, r--, winner--;
        int cur = l;
        int mn = INT_MAX;
        int mx = -1;
        int prevRoot = dsu.find(l);
        while (cur <= r) {
            int curRoot = dsu.find(cur);
            DsuNode knight = m[curRoot];
            ans[knight.index] = winner + 1;
            int newRoot = dsu.merge(prevRoot, curRoot);
            mn = min(knight.l, mn);
            mx = max(knight.r, mx);            
            m.erase(prevRoot);
            m.erase(curRoot);
            m.insert({ newRoot, DsuNode(winner, mn, mx) });   
            prevRoot = newRoot;
            cur = mx+1;
        }
    }
    int k = 1;
    for (int i : ans) {
        if (i == k++)  i = 0; 
        cout << i<< " ";
    }
    return 0;
}

