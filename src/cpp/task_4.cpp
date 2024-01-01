/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const int inf = numeric_limits<int>::max();
    vector<vector<pair<int, int>>> graph(n + 1); 
    vector<int> dist(n + 1, inf);

    
    for (const auto& edge : times) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        graph[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k}); 
    dist[k] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; 

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == inf) 
            return -1;
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}

int main() {
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4; 
    int k = 2; 

    int minTime = networkDelayTime(times, n, k);
    if (minTime != -1) {
        cout << minTime << endl;
    } else {
        cout << "It is impossible." << endl;
    }

    return 0;
}


//Runtime complexity  is O((E + V) log V).
//Memory complexity is O(V + E).