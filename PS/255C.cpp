
#include <iostream>
#include <vector>
#define MAX 4123
using namespace std;

int dp[MAX][MAX];

int main()
{
    int n;
    cin >> n;
    vector<int> data(MAX);
    for (int i = 1; i <= n; i++){
        cin >> data[i];
    }

    int ans = 1;
    for (int i = 1; i <= n; i++){
        int k = -1;
        for (int j = 1; j < i; j++){
            if (k == -1) dp[j][i] = 2;
            else dp[j][i] = dp[k][j] + 1;


            if (data[i] == data[j]) k = j;

            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans;
}