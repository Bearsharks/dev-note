#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    set< pair<ll, ll> > s;
    s.insert({ -1,-1 });
    s.insert({ 10e12+100 , 10e12 + 100 });
    for (long long n : room_number) {
        set<pair<ll, ll>>::iterator next = s.upper_bound({ n,n });
        set<pair<ll, ll>>::iterator prev;
        if (next->first == n) {
            prev = next;
            next++;
        }
        else {
            prev = next; prev--;
        }
        
        if (n <= prev->second+1) {
            answer.push_back(prev->second + 1);
            if (prev->second + 2 == next->first) {
                pair<ll, ll> newone = { prev->first, next->second };
                s.erase(prev);
                s.erase(next);
                s.insert(newone);
            }
            else {
                pair<ll, ll> newone = { prev->first, prev->second+1 };
                s.erase(prev);
                s.insert(newone);
            }
        }
        else {
            answer.push_back(n);
            if (next->first - 2 == prev->second) {
                pair<ll, ll> newone = { prev->first, next->second };
                s.erase(prev);
                s.erase(next);
                s.insert(newone);
            }
            else if(next->first - 1 == n){
                pair<ll, ll> newone = { n, next->second };
                s.erase(next);
                s.insert(newone);
            }
            else {
                s.insert({ n,n });
            }
        }
    }
    return answer;
}

int main() {
    vector<long long> v = solution(10, { 1, 3, 4, 1, 3, 1 });
    return 0;
}