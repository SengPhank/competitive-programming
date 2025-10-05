#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // starts at the top-left
    // get to bottom-right

    queue<pair<int, int>> bfs;
    if (grid[0][0] == '*' || grid[m-1][n-1] == '*') {
        cout << "FAIL" << endl;
        return 0;
    }
    visited[0][0] = true;
    bfs.push({0, 0});
    

    vector<pair<int, int>> dir = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    while (!bfs.empty()) {
        int row = bfs.front().first;
        int col = bfs.front().second;
        bfs.pop();

        for (pair<int, int> i : dir) {
            int newR = row + i.first;
            int newC = col + i.second;
            if (newR >= 0 && newR < m && newC >= 0 && newC < n) {
                if (!visited[newR][newC] && grid[newR][newC] == '.') {
                    visited[newR][newC] = true;
                    bfs.push({newR, newC});
                }
            }
        }
    }

    if (visited[m-1][n-1]) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    return 0;
}