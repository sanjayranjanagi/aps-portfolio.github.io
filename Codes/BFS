#include <iostream>
#include <vector>
#include <queue>

void bfs(int start, const std::vector<std::vector<int>>& adjList) {
    std::vector<bool> visited(adjList.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << "Visited node: " << node << "\n";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> adjList = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    bfs(0, adjList);
    return 0;
}
