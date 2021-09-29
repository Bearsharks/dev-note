#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
random_device rd;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
long long isPrime(long long n) {
    if (n <= 1)return 0;
    if (n % 2 == 0) return n == 2 ? 1 : 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    stringstream ss;
    while (n >= k) {
        ss << (n % k);
        n = n / k;
    }
    ss << n;
    string s = ss.str();
    reverse(s.begin(), s.end());


    vector<string> v = split(s, '0');
    for (string candi : v) {
        if (candi.size() == 0) continue;
        stringstream sss;
        sss << candi;
        long long number;
        sss >> number;
        answer += isPrime(number);
    }
    return answer;
}

int main() {
    solution(10210, 10);
    return 0;
}