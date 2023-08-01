#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// �� ���� ������ ������ � ���� �ٸ� ���� ������ ��,
// ���ԵǴ� ���� �ڽ����� �ϴ� Ʈ����� ���� ��, �θ� �ڽİ����� �̵� �� �� �ְ�,
// ���� �� S�� �� �� E�� ���� �θ� P��� �ϸ� s -> p -> e ��θ� ����ϸ� �ȴ�.

// �������� ū�� �ȿ� ���� ���� ��� �� �� �ְ�,
/*
    �׷��ٸ� ��������� ���Ľ�Ų���� ���Կ��θ� �Ǵ��ϸ� �׷����� �׸� �� �ִ�.
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
        else { // �ݾƾ���
            circles[cur].isOpened = false;
            int p = circles[cur].parent;
            // �ڽ� �ĺ��� ���𰡰� �ִٸ� ���� �θ�� �Ű���
            queue<int>& parentOpenChilds = circles[p].openChilds;
            while (!circles[cur].openChilds.empty()) {
                int front = circles[cur].openChilds.front();
                circles[cur].openChilds.pop();
                parentOpenChilds.push(front);
                // ���� �θ� ���� �θ���
                circles[front].parent = p;
            }
            // �������� �ڽ����� ���
            // �θ��� ù��°�� ���� �ڽ��� ���� ���� ������ �Ǿ����� �׷��� ť���� ���ϸ�
            // �ڽ� �ĺ����� ���� �Ϸ�
            circles[p].openChilds.pop();
            circles[p].child.insert(cur);
            if (lastOpenCircle == cur) {
                lastOpenCircle = circles[lastOpenCircle].parent;
            }
        }
    }
}

void trimGraph(vector<Circle>& circles) {
    // ��� ������ ���� ���� ���ڽ��� �´��� ����
    // �´ٸ� �ΰ� �ƴϸ� �θ�� �÷���
    for (int i = 1, last = circlexs.size(); i <= last; i++) {
        set<int> realChild;
        // x �������� �ڽ���
        // y �������� �ڽ��� �ƴϸ� �����Ѵ�.
        // y �������� �ڽ��� x�������� 
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
