#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m ;

    //행과 열을 각 차이마다 늘려가면서 얻을 수 있는 것이 제곱인지 아닌지를 판단합니다.
    //제곱이라면 최대와 비교하여 답을 구합니다.
    //뒤집어서도 비교합니다.
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
        //행의 최대 차이는 n-1이다.
        //열의 최대 차이는 m-1이다.
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