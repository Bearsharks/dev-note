#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

/*
/ 전략 : 무식하게 접근하면 10^6이고 모든 부분합의 갯수는 10^6^2 라서 1억을 넘는다.
/ 무식하게는 못품 N이나 NlogN의 시간복잡도에서 해결할수 있는 방법은?
/ 그래서 예제를 더해봄 1 3 6 7 9 <- 3은 되고 6되고 9된다. 
/ 6에서 3을 빼면 3이다. 7에서 1을 빼면 6이고 7에서 4를 빼면 3이다.
/ 그런데 4는 없고 1은 있다.
/ 결국 이전걸 빼서 M의 배수가 되면된다. 빼는 값이 있는지 없는지는 set으로 하면 logN으로 찾을 수 있다.
/ 그런데 m이 2라고 하면 10^9^2 까지 엄청 많은 숫자가 있을텐데? 10^9^2/2 x logN x N 은 안되는데?
/ 생각해보니 현재까지 합을 cur라고 하면 cur-m에서의 갯수에다 1더해준걸 답에 더하면 됨
/ 메모리를 아껴보자 m내에서 돌고 돌다. 결국 dp[cur%m]에서 cur가 딱 떨어지면 +1, 아니면 말면 됨
/ 이걸 위해 필요한 정보는 이전 누적합만 유지해두는 몇개의 변수를 제외하면 dp에 쓸 10^3 정도로 해결됨
/ 답은? 최악의 경우 모든 부분합의 갯수는 10^6^2이다. long long 이다.
*/

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    ull answer = 0;
    ull sum = 0;
    vector<ull> dp(m, -1);
    for (int i = 0; i < n; i++) {
        ull cur;
        cin >> cur;
        sum += cur;
        ull remain = sum % m;
        answer += remain == 0;
        answer += dp[remain] += 1;
    }
    cout << answer;

    return 0;
}

// 틀렸음. 놓친 부분은 한바퀴 돈다음부터 m을 뺏을 때 딱 떨어지는 숫자가 되기 때문,
// 한바퀴 돌기전에는 뺄녀석이 앞에 등장하지 않았기 때문
// 그래서 등장시 1을 더해서 0이 되도록 -1로 초기화함