#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    if (n & 1) return 0;
    vector<long long> v = { 0, 3, 11 };
    vector<long long> newone = { 0,0,2 };
    for (int i = 3; i <= n / 2; i++) {
        newone.push_back((newone[i - 1] + v[i - 2] * 2) % 1000000007);
        v.push_back((v[i - 1] * 3 + newone[i]) % 1000000007);
    }

    return v[n / 2];
}