#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// 전략 공통조상까지 너하나 나하나 타고 올라감
// 어떤 노드가 이미 나왔다면 그 노드가 부모 노드임
// 어떤 노드가 루트까지 가면 멈춤

class Node {
public:
    int nodeIdx;
    Node* parent;
};

int findLCA(Node n1, Node n2) {
    unordered_set<int> ancestors;
    // Traverse ancestors of n1 and store in a set
    while (true) {
        if (n1.nodeIdx != 0 && ancestors.count(n1.nodeIdx)) {
            return n1.nodeIdx;
        }
        else {
            ancestors.insert(n1.nodeIdx);
        }
        if (n2.nodeIdx != 0 && ancestors.count(n2.nodeIdx)) {
            return n2.nodeIdx;
        }
        else {
            ancestors.insert(n2.nodeIdx);
        }
        
        
        n1 = *n1.parent;
        n2 = *n2.parent;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        int n;
        cin >> n;
        vector<Node> v(n + 1);
        v[0].nodeIdx = 0;
        for (int i = 0; i < n; i++) {
            v[i].parent = &v[0];
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].nodeIdx = a;
            v[b].parent = &v[a];
            v[b].nodeIdx = b;
        }
        int a, b;
        cin >> a >> b;
        cout << findLCA(v[a], v[b]) << "\n";
    }
    return 0;
}