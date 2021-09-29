#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int getTime(string str) {
    int h = str[0] - '0' * 10 + str[1] - '0';
    int m = str[3] - '0' * 10 + str[4] - '0';
    int s = str[6] - '0' * 10 + str[7] - '0';
    return 3600 * h + 60 * m + s;
}
pair<int, int> getTimeline(string str) {    
    int h = str[9] - '0' * 10 + str[10] - '0';
    int m = str[12] - '0' * 10 + str[13] - '0';
    int s = str[15] - '0' * 10 + str[16] - '0';
    return { getTime(str),  3600 * h + 60 * m + s };
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int pt = getTime(play_time);
    int at = getTime(adv_time);
    vector<pair<int, int>> v;
    for (string s : logs) {
        v.push_back(getTimeline(s));
    }
    sort(v.begin(), v.end());

    int st = v[0].first;
    int et = st + at;
    int s = 0;
    int e;
    int curSum = 0;
    for (int i = 0, n = v.size(); i < n; i++) {
        if(v[i].first < et) 
        e = i;
        curSum += ((v[i].second <= et)? v[i].second : et) - v[i].first;
    }
    return answer;
}
int main() {
    vector<string> board = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };
    solution("02:03:55", "00:14:15", board);
    return 0;
}