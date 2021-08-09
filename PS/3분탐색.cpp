#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cal(vector<vector<int>>& land, int P, int Q, long long height) {
    int n = land.size();
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll need = height - land[i][j];
            ret += need > 0 ?  P * need : -Q * need;
        }
    }
    return ret;
}
long long solution(vector<vector<int>> land, int P, int Q) {
    ll answer = 1e11;
    ll mx = 1e10 + 1;
    ll mn = 0;
    while (mx > mn) {
        ll mid = (mx + mn) / 2;
        ll one = cal(land, P, Q, mid);
        ll two = cal(land, P, Q, mid + 1);
        
        if (one == two) {
            answer = one;
            break;
        }
        else if(one < two){
            answer = min(one, answer);
            mx = mid;
        }
        else {
            answer = min(two, answer);
            mn = mid + 1;
        }
    }
    return answer;
}

int main() {
    cout << solution({ {1,2},{2,3} }, 3, 2);
    return 0;
}