#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int test(int& a, int& b) {
    return a > b;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int d = dist.size();
    int w = weak.size();
    sort(dist.begin(), dist.end(), test);
    int sum = 0;
    vector<int> interd;
    for (int i = 1; i < w; i++) {
        interd.push_back(weak[i] - weak[i - 1]);
    }
    n--;
    interd.push_back(n - weak.back() + weak[0] - 0);
    sort(interd.begin(), interd.end(), test);
    int answer = -1;
    for (int i = 0; i < d; i++) {
        sum += dist[i];
        n -= interd[i];
        if (sum >= n) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

int main() {
    //cout << solution(12, { 1,5,6,10 }, { 1,2,3,4 }) << "\n";
   cout << solution(12, { 1,3,4,9,10 }, { 3, 5, 7 });
    return 0;
}