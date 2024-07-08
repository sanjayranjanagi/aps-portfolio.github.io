#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the distance between two points
double calculateDistance(pair<int, int> point1, pair<int, int> point2) {
    return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}

// Greedy TSP function
vector<int> greedyTSP(vector<pair<int, int>>& events) {
    int n = events.size();
    vector<int> path;
    vector<bool> visited(n, false);
    
    path.push_back(0);
    visited[0] = true;
    
    for (int i = 0; i < n - 1; ++i) {
        int current = path.back();
        double minDist = numeric_limits<double>::max();
        int next = -1;
        
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double dist = calculateDistance(events[current], events[j]);
                if (dist < minDist) {
                    minDist = dist;
                    next = j;
                }
            }
        }
        
        path.push_back(next);
        visited[next] = true;
    }
    
    // Return to the starting point
    path.push_back(0);
    return path;
}

int main() {
    // Example event locations (x, y coordinates)
    vector<pair<int, int>> events = {
        {0, 0}, {2, 3}, {5, 2}, {6, 6}, {8, 3}
    };
    
    vector<int> path = greedyTSP(events);
    
    cout << "Optimal event path: ";
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
