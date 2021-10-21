#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

long long cal(long long a, long long b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    return a * b;
}
long long solution(string expression) {
    long long answer = 0;
    int prev = 0;
    set<pair<int, long long>> ns;
    set<pair<int, char>> oper;
    int i = 0;
    for (char c : expression) {
        if ('0' <= c && c <= '9') {
            prev = prev * 10 + (c - '0');
        }
        else {
            ns.insert({ i,prev });
            oper.insert({ i,c });
            prev = 0;
            i++;
        }
    }
    ns.insert({ i,prev });

    vector<char> a = { '-','+','*' };
    sort(a.begin(), a.end());
    do {
        set<pair<int, long long>> nscopy = ns;
        set<pair<int, char>> opercopy = oper;
        for (char o : a) {
            auto nsiter = nscopy.begin();
            auto operiter = opercopy.begin();
            while (operiter != opercopy.end()) {
                if (operiter->second == o) {
                    auto next = nsiter; next++;
                    pair<int, long long> newVal =
                    { nsiter->first, cal(nsiter->second,next->second,o) };
                    operiter = opercopy.erase(operiter);
                    nscopy.erase(nsiter);
                    nscopy.erase(next);
                    nsiter = nscopy.insert(newVal).first;
                }
                else {
                    operiter++;
                    nsiter++;
                }
            }            
        }
        long long candi = nscopy.begin()->second;
        candi = candi > 0 ? candi : -candi;
        answer = max(candi, answer);
    } while (next_permutation(a.begin(), a.end()));
    return answer;
}
int main() {
    
        string s;
    cin >> s;
    cout << solution(s);
    return 0;
}