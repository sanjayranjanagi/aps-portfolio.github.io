#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

vector<int> hungarianAlgorithm(vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    vector<int> u(n, 0), v(n, 0), p(n, 0), way(n, 0);
    for (int i = 1; i < n; ++i) {
        vector<int> minv(n, INF);
        vector<bool> used(n, false);
        int j0 = 0;
        p[0] = i;
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j < n; ++j) {
                if (!used[j]) {
                    int cur = costMatrix[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }
    vector<int> assignment(n - 1);
    for (int j = 1; j < n; ++j) {
        assignment[p[j] - 1] = j;
    }
    return assignment;
}

int main() {
    vector<vector<int>> costMatrix = {
        {0, 0, 0, 0},
        {0, 2, 3, 3},
        {0, 3, 2, 3},
        {0, 3, 3, 2}
    };
    vector<int> assignment = hungarianAlgorithm(costMatrix);
    cout << "Optimal assignment: ";
    for (int i = 0; i < assignment.size(); ++i) {
        cout << "Person " << i + 1 << " to Task " << assignment[i] << " ";
    }
    cout << endl;
    return 0;
}
