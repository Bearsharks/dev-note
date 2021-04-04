#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solution(int n, int k, vector<long long>& numbers) {
    long double answer = 987654321;
    vector<long double> powsum = { 0 };
    vector<long double> sum = { 0 };
    for (int i = 0; i < n; i++) {
        sum.push_back(sum.back() + numbers[i]);
        powsum.push_back(powsum.back() + numbers[i] * numbers[i]);
    }
    for (int i = 1; i <= n - (k - 1); i++) {
        for (int j = i + k - 1; j <= n; j++) {
            int num = (j - i + 1);
            long double m = (sum[j] - sum[i - 1]) /(num);
            long double candi = (powsum[j] - powsum[i - 1]) - 2 * (sum[j] - sum[i - 1]) * m  + m * m * num;
            answer = min(answer, sqrt(candi / num));
        }
    }    
    cout << answer << endl;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout.setf(ios::fixed);
    cout.precision(15);
    solution(n, k, numbers);
    return 0;
}