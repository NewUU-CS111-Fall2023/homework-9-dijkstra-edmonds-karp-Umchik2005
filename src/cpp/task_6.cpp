/*
 * Date: 01/01/2024
 * Name: Muhammad Umar Toshpo'latov
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k, int f) {
    const int inf = numeric_limits<int>::max();
    unordered_map<int, vector<pair<int, pair<int, int>>>> graph;
    for (const auto& flight : flights) {
        graph[flight[0]].push_back({flight[1], {flight[2], flight[3]}});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0, f});

    while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();

        int distance = curr[0];
        int city = curr[1];
        int stops = curr[2];
        int fuel = curr[3];

        if (city == dst) {
            return distance; 
        }

        if (stops > k || fuel < 0) {
            continue; 
        }

        for (const auto& neighbor : graph[city]) {
            int nextCity = neighbor.first;
            int nextDistance = neighbor.second.first;
            int hasRefuelStation = neighbor.second.second;

            int newFuel = fuel - nextDistance;
            if (newFuel >= 0 || hasRefuelStation == 1) {
                pq.push({distance + nextDistance, nextCity, stops + 1, f - nextDistance + (hasRefuelStation == 1 ? f : 0)});
            }
        }
    }

    return -1; 
}

int main() {
    int n = 5;
    vector<vector<int>> flights = {{0, 1, 100, 0}, {1, 2, 100, 1}, {0, 2, 500, 0}};
    int src = 0;
    int dst = 2;
    int k = 1;
    int f = 300;

    int shortestPath = findCheapestPrice(n, flights, src, dst, k, f);

    if (shortestPath != -1) {
        cout << shortestPath << endl;
    } else {
        cout << "No such route." << endl;
    }

    return 0;
}
//Runtime complexity is O(E * log V).
//Memory complexity is O(E + V).
