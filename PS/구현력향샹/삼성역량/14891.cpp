#include <iostream>
#include <vector>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
class gear {
public:
	gear(vector<bool> vv):v(vv) {

	}
	void rot(int d){
		cur = (8+cur - d) % 8;
	};
	bool get3() {
		return v[(cur + 2) % 8];
	};
	bool get9() {
		return v[(cur + 6) % 8];
	};
	bool get12() {
		return v[cur];
	};
private:
	vector<bool> v;
	int cur = 0;
};
void rot(int i, int d, vector<gear> & gears) {	
	//오른쪽으로
	int right = gears[i].get3();
	int cur = i;
	int curd = d;
	int next = cur + 1;
	while (next < 4) {		
		int nextleft = gears[next].get9();
		if (nextleft == right) break;//종료조건 같은 극이면 돌지 않으므로 종료

		right = gears[next].get3();
		gears[next].rot(-curd);
		cur = next;
		curd = -curd;
		next = cur + 1;		
	}
	//왼쪽으로
	int left = gears[i].get9();
	cur = i;
	curd = d;
	next = cur - 1;
	while (next >= 0) {
		int nextright = gears[next].get3();
		if (nextright == left) break;//종료조건 같은 극이면 돌지 않으므로 종료

		left = gears[next].get9();
		gears[next].rot(-curd);
		cur = next;
		curd = -curd;
		next = cur - 1;
	}
	gears[i].rot(d);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<gear> gears;
	for (int i = 0; i < 4; i++) {
		vector<bool> tmp;
		string s;
		cin >> s;
		for (char c : s) {
			if (c == '1') tmp.push_back(1);
			else tmp.push_back(0);
		}
		gears.push_back(gear(tmp));
	}
	int n;
	cin >> n;
	while (n--) {
		int i, d;
		cin >> i >> d;
		rot(--i, d, gears);
	}
	int result = 0;
	for (int i = 0; i < 4; i++) {
		bool isS = gears[i].get12();
		if(isS) result += 1 << i;
	}
	cout << result;
	return 0;
}