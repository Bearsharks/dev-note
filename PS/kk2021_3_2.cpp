#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

bool dec(int& a, int& b) {
    return a > b;
}
int strToBit(string lang, string kind, string career, string soul) {
    int bit = 0;
    if (lang[0] == 'j') bit += 1;
    else if (lang[0] == 'p') bit += 2;
    else if (lang[0] == 'c')bit += 3;
    

    if (kind[0] == 'b') bit += 1 << 2;
    else if(kind[0] == 'f') bit += 2 << 2;

    if (career[0] == 'j') bit += 1 << 4;
    else if (career[0] == 's') bit += 2 << 4;

    if (soul[0] == 'c') bit += 1 << 6;
    else if (soul[0] == 'p') bit += 2 << 6;

    return bit;
}
void bitset(unordered_map<int, vector<int>>& bitmap, string str) {
    istringstream istr(str);
    
    int score;
    string lang, kind, career, soul;
    istr >> lang >> kind >> career >> soul >> score;
    int bit = strToBit(lang, kind, career, soul);
    //4c0
    bitmap[0].push_back(score);
    //4c1
    bitmap[bit & (3)].push_back(score);
    bitmap[bit & (3 << 2)].push_back(score);
    bitmap[bit & (3 << 4)].push_back(score);
    bitmap[bit & (3 << 6)].push_back(score);
    //4c2
    bitmap[bit & ~(15)].push_back(score);
    bitmap[bit & ~(15 << 2)].push_back(score);
    bitmap[bit & ~(15 << 4)].push_back(score);
    bitmap[bit & ~(51)].push_back(score);
    bitmap[bit & ~(51 << 2)].push_back(score);
    bitmap[bit & ~(195)].push_back(score);
    //4c3
    bitmap[bit & ~(3)].push_back(score);
    bitmap[bit & ~(3 << 2)].push_back(score);
    bitmap[bit & ~(3 << 4)].push_back(score);
    bitmap[bit & ~(3 << 6)].push_back(score);  
    //4c4
    bitmap[bit].push_back(score);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<int, vector<int>> bitMap;
    for (int i = 0; i < info.size(); i++) {
        bitset(bitMap, info[i]);
    }
    for (int i = 0; i < query.size(); i++) {
        istringstream istr(query[i]);
        string lang, kind, career, soul, tmp;
        int base;
        istr >> lang >> tmp >> kind >> tmp >> career >> tmp >> soul >> base;
        int bit = strToBit(lang, kind, career, soul);
        int cnt = 0;
        for (int score : bitMap[bit]) {
            if (score >= base) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    vector<string> orders = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> course = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> res = solution(orders, course);
    for (int r : res) {
        cout << r << " ";
    }
    return 0;
}