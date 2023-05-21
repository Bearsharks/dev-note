#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 원은 교점이 없으니 어떤 원은 다른 원에 포함이 됨,
// 포함되는 원을 자식으로 하는 트리라고 봤을 때, 부모 자식간에만 이동 할 수 있고,
// 시작 원 S과 끝 원 E의 공통 부모를 P라고 하면 s -> p -> e 경로를 출력하면 된다.
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n = 0;
    int s, e;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int k, x, r;
        cin >> k >> x >> r;
        // 왼쪽과 오른쪽 점을 기억 해둠 그리고 그 점이 어디 원에 포함되는지 저장해 둠 교점이 없어서 가능
        v.push_back({ x - r, k });
        v.push_back({ x + r, k });
    }
    cin >> s >> e;

    // 페어는 정렬하면 우선순위가 first부터 이므로 각 원이 이런 모양으로 정렬 될 것-> ((()())(()))
    sort(v.begin(), v.end());

    vector<int> stack(0);
    vector<int> path1(0), path2(0);

    // 루트인 0 부터 트리 구성 시작 
    stack.push_back(0);
    // ((()())(()) 이걸 순회 할 것 
    for (int i = 0; i < 2 * n; i++) {
        //스택 탑에 있는 원이 현재 원의 부모가 됨
        int prev = stack.back();
        int cur = v[i].second;
        stack.push_back(cur);

        if (prev == cur) {
            // 스택 탑의 원과 현재 원이 같으면 () 이런 상태니까 스택에서 제거함
            stack.pop_back();
            if (cur == s) {
                // 현재 원이 시작 원 이라면 현재 스택에 들어있는 값은 루트부터 시작 원 까지의 경로
                path1 = stack;
            }
            else if (cur == e) {
                // 현재 원이 끝 원 이라면 현재 스택에 들어있는 값은 루트부터 끝 원 까지의 경로
                path2 = stack;
            }
            stack.pop_back();
        }
    }

    int sameParent;
    for (int i = 0; path1[i] == path2[i]; i++) {
        sameParent = i;
    }

    // 시작원에서 공통부모 전까지의 거리 + 공통 부모에서 끝점까지의 거리 = 전체 이동 거리
    cout << path1.size() - sameParent + path2.size() - sameParent - 1 << "\n";
    for (int i = path1.size() - 1; i > sameParent; i--) {
        cout << path1[i] << " ";
    }

    // 출력 시 " "가 마지막에 들어가는 것을 방지하기 위해 첫번째껄 미리 출력함
    cout << path1[sameParent];
    for (int i = sameParent + 1; i < path2.size(); i++) {
        cout << " " << path2[i];
    }
    return 0;
}
