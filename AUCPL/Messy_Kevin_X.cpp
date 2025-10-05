#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> paths;
    for (int i = 0; i < m; i++) {
        int node, path;
        cin >> node >> path;
        paths[node].insert(path);
    };

    int begi, endi;
    cin >> begi >> endi;

    queue<pair<int, int>> bfs; // {path. how much traversal}
}