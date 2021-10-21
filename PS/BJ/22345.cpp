#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector < pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> b >> a;
        v.push_back({ a,b });
    }
    vector<pair<int,int>> pos;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        pos.push_back({ a,i });
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(pos.begin(), pos.end());
    long long totalL = 0;
    long long totalR = 0;
    long long d = 0;
    long long p = pos[0].first;
    for (int i = n-1; i >= 0 ; i--) {
        d += abs(v[i].first - p) * v[i].second;
        if (v[i].first <= p) {
            totalL += v[i].second;
            v.pop_back();
        }
        else totalR += v[i].second;
    }
    vector<long long> answer(q);
    answer[pos[0].second] = d;
    long long prev = p;
    for (int i = 1; i < q; i++) {
        vector<pair<int,int>> newLs;
        while (v.size() && v.back().first <= pos[i].first) {
            totalR -= v.back().second;
            newLs.push_back(v.back());
            v.pop_back();            
        }
        d -= totalR * (pos[i].first - prev);
        d += totalL * (pos[i].first - prev);
        for (pair<int, int> XandA : newLs) {
            d -= XandA.second * (XandA.first - prev);
            d += XandA.second * ((long long)pos[i].first - XandA.first);
            totalL += XandA.second;
        }
        prev = pos[i].first;
        answer[pos[i].second] = d;
    }
    for (long long i : answer) {
        cout << i << "\n";
    }
    return 0;
}