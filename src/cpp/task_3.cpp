/*
 * Date: 01/01/2024
 * Name: Muhammad Umar Toshpo'latov
 */

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct Point {
    int x, y;
};

bool isOK(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int shortestPath(vector<vector<char>>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<pair<Point, int>> q;
    q.push({start, 0});
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (current.x == end.x && current.y == end.y) {
            return distance; 
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isOK(newX, newY, rows, cols) && maze[newX][newY] == '.' && !visited[newX][newY]) {
                q.push({{newX, newY}, distance + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1; 
}

int main() {
    vector<vector<char>> maze = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'S', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '#', '.', 'E'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    Point start = {1, 0}; 
    Point end = {4, 8};  

    int shortest = shortestPath(maze, start, end);

    if (shortest != -1) {
        cout << "Shortest path length: " << shortest << endl;
    } else {
        cout << "No path found to the exit!" << endl;
    }

    return 0;
}

//Runtime complexity is O(rows * cols).
//Memory complexity is O(rows * cols).