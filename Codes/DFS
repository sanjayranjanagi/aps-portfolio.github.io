#include <iostream>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << "Visited node: " << node << "\n";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
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

    std::vector<bool> visited(adjList.size(), false);
    dfs(0, adjList, visited);
    return 0;
}
