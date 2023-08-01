#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// 각 원은 교점이 없으니 어떤 원은 다른 원에 포함이 됨,
// 포함되는 원을 자식으로 하는 트리라고 봤을 때, 부모 자식간에만 이동 할 수 있고,
// 시작 원 S과 끝 원 E의 공통 부모를 P라고 하면 s -> p -> e 경로를 출력하면 된다.

// 반지름이 큰원 안에 작은 원이 들어 갈 수 있고,
/*
    그렇다면 반지름대로 정렬시킨다음 포함여부를 판단하면 그래프를 그릴 수 있다.
*/

class Circle {
public:
    bool isOpened = false;
    queue<int> openChilds;
    set<int> child;
    int parent;
};

void makeGraph(vector<pair<int, int>>& v, vector<Circle>& circles) {
    int lastOpenCircle = 0;
    for (int i = 0,last = v.size(); i < last; i++) {
        int cur = v[i].second;
        if (!circles[cur].isOpened) {
            circles[cur].isOpened = true;
            circles[cur].parent = lastOpenCircle;
            circles[lastOpenCircle].openChilds.push(cur);
            lastOpenCircle = cur;
        }
        else { // 닫아야함
            circles[cur].isOpened = false;
            int p = circles[cur].parent;
            // 자식 후보에 무언가가 있다면 나의 부모로 옮겨줌
            queue<int>& parentOpenChilds = circles[p].openChilds;
            while (!circles[cur].openChilds.empty()) {
                int front = circles[cur].openChilds.front();
                circles[cur].openChilds.pop();
                parentOpenChilds.push(front);
                // 나의 부모가 너의 부모임
                circles[front].parent = p;
            }
            // 닫혔으니 자식으로 등록
            // 부모의 첫번째로 열린 자식이 가장 먼저 닫히게 되어있음 그러니 큐에서 팝하면
            // 자식 후보에서 제거 완료
            circles[p].openChilds.pop();
            circles[p].child.insert(cur);
            if (lastOpenCircle == cur) {
                lastOpenCircle = circles[lastOpenCircle].parent;
            }
        }
    }
}

void trimGraph(vector<Circle>& circles) {
    // 모든 정점에 대해 정말 내자식이 맞는지 검증
    // 맞다면 두고 아니면 부모로 올려줌
    for (int i = 1, last = circlexs.size(); i <= last; i++) {
        set<int> realChild;
        // x 관점에서 자식이
        // y 관점에서 자식이 아니면 제거한다.
        // y 관점에서 자식이 x관점에서 
        for (int c : circlexs[i].child) {
            if (circleys[i].child.count(c)) {
                realChild.insert(c);
            }
        }
        circlexs[i].child = realChild;
    }
}

int getMaxPathLength(vector<Circle>& circles) {
    return 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n = 0;
    int s, e;
    cin >> n;
    vector<pair<int, int>> vx;
    vector<pair<int, int>> vy;

    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        
        vx.push_back({ x - r, i });
        vx.push_back({ x + r, i });
        vy.push_back({ y - r, i });
        vy.push_back({ y + r, i });
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    vector<Circle> circles(n + 1);
    makeGraph(vx, circles);
    return 0;
}
