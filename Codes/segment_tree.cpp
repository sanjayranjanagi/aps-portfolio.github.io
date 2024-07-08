#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void buildTree(vector<int>& data, int start, int end, int node) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = start + (end - start) / 2;
            buildTree(data, start, mid, 2 * node + 1);
            buildTree(data, mid + 1, end, 2 * node + 2);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void updateRange(int start, int end, int l, int r, int value, int node) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            return;
        }

        if (start >= l && end <= r) {
            tree[node] += value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        int mid = start + (end - start) / 2;
        updateRange(start, mid, l, r, value, 2 * node + 1);
        updateRange(mid + 1, end, l, r, value, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int queryRange(int start, int end, int l, int r, int node) {
        if (start > end || start > r || end < l) {
            return INT_MAX;
        }

        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftQuery = queryRange(start, mid, l, r, 2 * node + 1);
        int rightQuery = queryRange(mid + 1, end, l, r, 2 * node + 2);
        return min(leftQuery, rightQuery);
    }

public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(data, 0, n - 1, 0);
    }

    void updateRange(int l, int r, int value) {
        updateRange(0, n - 1, l, r, value, 0);
    }

    int queryRange(int l, int r) {
        return queryRange(0, n - 1, l, r, 0);
    }
};

int main() {
    vector<int> serverLoads = {5, 3, 8, 6, 2, 7, 4};
    SegmentTree st(serverLoads);

    cout << "Minimum load between servers 1 and 4: " << st.queryRange(1, 4) << endl;

    st.updateRange(2, 5, -2);
    cout << "Minimum load between servers 1 and 4 after update: " << st.queryRange(1, 4) << endl;

    return 0;
}
