#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int cnt = 0;    
    vector<pair<int, int>> v;
    for (int t : food_times) {
        v.push_back({ t, cnt++ });
    }
    sort(v.begin(), v.end(),greater<pair<int,int>>());
    int prev = 0;
    while (!v.empty()) {
        if ((v.back().first - prev) * v.size() <= k) {
            k -= (v.back().first - prev) * v.size();
            prev = v.back().first;
            v.pop_back();
            if (v.empty()) return -1;
        }
        else {
            break;
        }
    }
    sort(v.begin(), v.end(), comp);
    int idx = k % v.size();
    return v[idx].second+1;
}
int main() {
    cout << solution({ 3, 1, 2 },6);
    return 0;
}