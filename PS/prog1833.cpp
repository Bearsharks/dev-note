#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    vector<pair<int,int>> vv;
    
    for (vector<int>& d : data) {
        vv.push_back({ d[0],d[1] });
    }
    sort( vv.begin(),vv.end());
    int prev = -1;

    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        if (vv[i].first != prev) {
            v.push_back(vector<int>());
            prev = vv[i].first;
        }
        v.back().push_back(vv[i].second);
    }

    for (int i = 0; i < v.size()-1; i++) {
        
        
        for (int j = 0; j < v[i].size(); j++) {
            //1. 초기 위 아래는 +inf -inf이다.
            int up = 2147483647;
            int down = -1;
            
            for (int k = i + 1; k < v.size(); k++) {
                //2. 다음 x에 있는 것 중 위 아래 사이의 쐐기갯수를 답에다 더한다.
                vector<int>::iterator u = upper_bound(v[k].begin(), v[k].end(), up);
                vector<int>::iterator l = lower_bound(v[k].begin(), v[k].end(), down);
                answer += u - l;
                //2. 내 y값의 바로 위, 바로 아래를 구한다. 그것이 다음 위, 아래가 된다.
                int curY = v[i][j];
                l = lower_bound(v[k].begin(), v[k].end(), curY);
                if (l != v[k].end() && *l == curY) {
                    answer--;
                }
                int nextDown = (l == v[k].begin()) ? -1 : *(--l);
                u = upper_bound(v[k].begin(), v[k].end(), curY);
                int nextUp = u == v[k].end() ? INT_MAX : *u;
                up = min(up, nextUp);
                down = max(down, nextDown);
            }
            //3. 모든 쐐기에 대해 이를 반복한다.
        }
        
    }
    return answer;
}

int main() {
    cout << solution(4, { {0, 0},{1, 1},{0, 2},{2, 0} });
    return 0;
}