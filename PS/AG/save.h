
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include "../DS/dsu.h"
using namespace std;
/*
* 
#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	//cout.setf(ios::fixed);
	//cout.precision(5);
	return 0;
}
//printf("%.9f %.9f\n", cur.first, cur.second);
//scanf("%lf %lf %d", &a, &d, &n);
//v[1~n]에서 longest increasing subsequence를 구하는 알고리즘
vector<int> ans = { -1,INT_MAX };
for (int i = 1; i <= n; i++) {
    int min = 0;
    int max = ans.size()-1;
    while (min < max) {
        int mid = (min + max) / 2;

        if (ans[mid] < v[i]) {
            min = mid + 1;
        }
        else if (ans[mid] > v[i])  {
            max = mid;
        }
        else {
            break;
        }
    }
    if (max == ans.size() - 1) {
        ans.push_back(INT_MAX);
    }
    ans[max] = v[i];
}

pair<int, int> D[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int isvisit[50][50] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector<string> v(50);

bool dfs(pair<int, int> start, pair<int, int> cur) {
	isvisit[cur.first][cur.second] = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m
            && !isvisit[nextx][nexty] && dfs(start, { nextx, nexty }) )
        {
			return true;
		}
	}
	return false;
}

//중복조합 n H i = n + i - 1 C i
int maxn = 1010;
void getcombi(int maxn){
	vector<vector<long long>> combi(maxn,vector<long long>(maxn));
	combi[0][0] = 1;
	for (int i = 1; i < maxn; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]);
		}
	}
}

	//부분합 만들기 m개씩 더하는
	for (int i = 1; i <= n; i++) {
		v[i] += v[i - 1];
	}
	int cur = 1;
	for (int i = n-m+1; i <= n; i++) {
		save[cur] = v[i] - v[cur-1];
		cur++;
	}

	난수
	#include <random>
	random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());

	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(0, 500);
*/

vector<int> sp(vector<vector<pair<int,int>>> graph, int start) {
	vector<int> result(graph.size(),INT_MAX);
	result[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		pair<int,int> cur = pq.top();
		pq.pop();
		int cost = -cur.first;
		int curidx = cur.second;
		if (cost > result[curidx]) continue;

		for (pair<int,int> adj : graph[curidx]) {
			if (result[adj.second] > cost + adj.first) {
				result[adj.second] = cost + adj.first;
				pq.push({ -(cost + adj.first), adj.second });
			}
		}
	}
	
	return result;
}

void fwsp(vector<vector<int>>& adj) {
	int n = adj.size();
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

vector<int> getpartialmatch(string& n) {
	int begin = 1;
	int matched = 0;
	vector<int> res(n.size());
	while (begin + matched < n.size()) {
		if (n[begin + matched] == n[matched]) {
			matched++;
			res[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - res[matched-1];
				matched = res[matched - 1];
			}
		}
	}
}
vector<int> kmps(string& h, string& n) {

}

const int MAX_V = 501;
int V;
vector<pair<int, int>> adj[MAX_V];

bool bellmanFord(int src) {
	//음수 사이클이 있다면 빈벡터를 반환할것임
	vector<int> upper(V, 987654321);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) return true;
	return false;
}

//v는 자기자신으로 가는 값이 0으로 초기화되어있어야
//갈수없으면 infinity가 되어야함
void fw(vector<vector<int>>& v) {
	int n = v.size();
	for (int c = 0; c < n; c++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = min(v[i][c] + v[c][j], v[i][j]);
			}
		}
	}
}

void topology_sort(vector<bool>& visit, vector<vector<int>>& graph, vector<int>& result, int cur) {
	visit[cur] = true;
	for (int c : graph[cur]) {
		if (!visit[c]) topology_sort(visit, graph, result, c);
	}
	result.push_back(cur);
	return;
}
//reverse(result.begin(), result.end());

//최소스패닝트리 알고리즘 O(eloge)
vector<tuple<long long, int, int>> Kruskal(vector<tuple<long long, int, int>>& edge, int v) {
	sort(edge.begin(), edge.end());
	long long answer = 0;
	DSU dsu(v + 1);
	vector<tuple<long long, int, int>> result;
	for (int i = 0, size = edge.size(); i < size; i++) {
		int a = get<1>(edge[i]);
		int b = get<2>(edge[i]);
		if (dsu.find(a) == dsu.find(b)) continue;
		result.push_back(edge[i]);
		if (dsu.merge(a, b)) {
			if (dsu.getSize(a) == v) break;
		}
	}
	return result;
}

vector<tuple<long long, int, int>> prim(vector<vector<pair<int, long long>>>& graph, int v) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater< pair<long long, int>>> minNode;
	vector<bool> added(v + 1, false);
	vector<int> parent(v + 1);
	vector<tuple<long long, int, int>> result;
	long long answer = 0;
	minNode.push({ 0,1 });
	parent[1] = 1;
	while (!minNode.empty()) {
		pair<long long, int> cur = minNode.top();
		minNode.pop();
		if (added[cur.second]) continue;
		added[cur.second] = 1;
		answer += cur.first;
		if (parent[cur.second] != cur.second) {
			result.push_back({ cur.first, parent[cur.second], cur.second });
		}

		for (pair<long long, int> p : graph[cur.second]) {
			if (!added[p.second]) {
				minNode.push(p);
				parent[p.second] = cur.second;
			}
		}
	}
	return result;
}

class Trie {
private:
	Trie* child[26];
	int count;
public:
	Trie() : child(), count(0) {}
	void Insert(string str) {
		Trie* now = this;
		for (char ch : str) {
			now->count++;
			if (now->child[ch - 'a'] == nullptr) now->child[ch - 'a'] = new Trie();
			now = now->child[ch - 'a'];
		}
	}

	int Search(string str) {
		Trie* now = this;
		for (char ch : str) {
			if (ch == '?') return now->count;
			now = now->child[ch - 'a'];
			if (now == nullptr) break;
		}
		return 0;
	}
};

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}