
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0];
    int basicFee = fees[1];
    int time = fees[2];
    int fee = fees[3];
    map<int, int> totalTimes;
    map<int, int> carParkingTime;
    for (int i = 0; i < records.size(); i++) {
        int  car, time, timeh, timem;
        bool isIn;
        timeh = (records[i][0] - '0') * 10 + (records[i][1] - '0');
        timem = (records[i][3] - '0') * 10 + (records[i][4] - '0');
        time = timeh * 60 + timem;
        car = (records[i][6] - '0') * 1000 + (records[i][7] - '0') * 100 + (records[i][8] - '0') * 10 + records[i][9] - '0';
        isIn = records[i][11] == 'I';
        if (isIn) {
            carParkingTime[car] = time;
        }
        else {
            totalTimes[car] += time - carParkingTime[car];
            carParkingTime.erase(car);
        }
    }
    int outTime = 23 * 60 + 59;
    for (auto iter = carParkingTime.begin(); iter != carParkingTime.end(); iter++) {
        totalTimes[iter->first] += outTime - iter->second;
    }
    for (auto iter = totalTimes.begin(); iter != totalTimes.end(); iter++) {
        int remain = iter->second - basicTime;
        if (remain <= 0) answer.push_back(basicFee);
        else {
            int cnt = remain / time;
            cnt += !!(remain % time);
            answer.push_back(cnt * fee + basicFee);
        }
    }
    return answer;
}

int main() {
    vector<int> fee = { 120, 0, 60, 591 };
    vector<string> record = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    solution(fee, record);
    return 0;
}