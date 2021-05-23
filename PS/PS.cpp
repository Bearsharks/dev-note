/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sp(vector<vector<pair<int, int>>> graph, int start) {
    vector<int> result(graph.size(),INT_MAX);
    result[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int cost = -cur.first;
        int i = cur.second;
        if (result[i] < cost) continue;
        for (pair<int, int> adj : graph[i]) {
            if (adj.first + cost < result[adj.second]) {
                result[adj.second] = cost + adj.first;
                pq.push({ -(adj.first + cost), adj.second });
            }
        }
    }


    return result;
}*/
