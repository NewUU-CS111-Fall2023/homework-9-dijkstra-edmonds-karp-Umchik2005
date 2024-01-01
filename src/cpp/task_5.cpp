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

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& flight : flights) {
        graph[flight[0]].push_back({flight[1], flight[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();

        int cost = curr[0];
        int city = curr[1];
        int stops = curr[2];

        if (city == dst) {
            return cost; 
        }

        if (stops > k) {
            continue; 
        }

        for (const auto& neighbor : graph[city]) {
            int nextCity = neighbor.first;
            int nextCost = neighbor.second;

            pq.push({cost + nextCost, nextCity, stops + 1});
        }
    }

    return -1; 
}

int main() {
    int n = 5;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    int cheapestPrice = findCheapestPrice(n, flights, src, dst, k);

    if (cheapestPrice != -1) {
        cout << cheapestPrice << endl;
    } else {
        cout << "No such route." << endl;
    }

    return 0;
}


//Runtime complexity is O(E * log V).
//Memory complexity is O(E + V).
