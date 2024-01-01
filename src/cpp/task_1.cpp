/*
 * Date: 01/01/2024
 * Name: Muhammad Umar Toshpo'latov
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Edge {
    int destination;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start) {
    int V = graph.size();
    vector<int> distance(V, INF); 
    distance[start] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& e : graph[u]) {
            int v = e.destination;
            int w = e.weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF)
            cout << "INF\n";
        else
            cout << distance[i] << "\n";
    }
}

int main() {
    int V, E; 
    cout << "Enter # of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter edges:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    int startVertex;
    cout << "Enter the start: ";
    cin >> startVertex;

    dijkstra(graph, startVertex);

    return 0;
}
/*
Runtime complexity O((V + E) log V).
Memory complexity is O(V + E).
*/