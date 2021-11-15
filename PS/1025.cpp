#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m ;

    //��� ���� �� ���̸��� �÷����鼭 ���� �� �ִ� ���� �������� �ƴ����� �Ǵ��մϴ�.
    //�����̶�� �ִ�� ���Ͽ� ���� ���մϴ�.
    //������� ���մϴ�.
    int answer = -1;
    vector<vector<int>> mat;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<int> tmp;
        while (a) {
            tmp.push_back(a % 10);
            a /= 10;
        }
        while (tmp.size() < m) tmp.push_back(0);
        reverse(tmp.begin(), tmp.end());
        mat.push_back(tmp);
    }
        //���� �ִ� ���̴� n-1�̴�.
        //���� �ִ� ���̴� m-1�̴�.
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == 0) continue;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {                    
                    v.clear();
                    int nexti = x;
                    int nextj = y;
                    while (0 <= nexti && nexti < n && 0 <= nextj && nextj < m) {
                        v.push_back(mat[nexti][nextj]);
                        int a = 0;
                        int b = 0;
                        for (int cur = 0; cur < v.size(); cur++) {
                            a = a * 10 + v[cur];
                            b = b * 10 + v[v.size() - 1 - cur];
                        }
                        int sqrta = (int)sqrt(a);
                        if (sqrta * sqrta == a) answer = max(answer, a);
                        int sqrtb = (int)sqrt(b);
                        if (sqrtb * sqrtb == b) answer = max(answer, b);
                        nexti += i;
                        nextj += j;
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}