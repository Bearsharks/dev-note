#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
            //1. �ʱ� �� �Ʒ��� +inf -inf�̴�.
            int up = 2147483647;
            int down = -1;
            
            for (int k = i + 1; k < v.size(); k++) {
                //2. ���� x�� �ִ� �� �� �� �Ʒ� ������ ���ⰹ���� �信�� ���Ѵ�.
                vector<int>::iterator u = upper_bound(v[k].begin(), v[k].end(), up);
                vector<int>::iterator l = lower_bound(v[k].begin(), v[k].end(), down);
                answer += u - l;
                //2. �� y���� �ٷ� ��, �ٷ� �Ʒ��� ���Ѵ�. �װ��� ���� ��, �Ʒ��� �ȴ�.
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
            //3. ��� ���⿡ ���� �̸� �ݺ��Ѵ�.
        }
        
    }
    return answer;
}

int main() {
    cout << solution(4, { {0, 0},{1, 1},{0, 2},{2, 0} });
    return 0;
}