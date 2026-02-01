#include <bits/stdc++.h>
using namespace std;

void op(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    op();
    int m, n;
    cin >> m >> n;

    // Apply padding
    vector<vector<int>> grid(m, vector<int>(n+2));
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n+1; j++) {
            cin >> grid[i][j];
        }
    }

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n+2; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // Minimum cost from top left to bottom right
    vector<vector<int>> minCost(m, vector<int>(n+2, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,0,0}); // cost, i, j (of the player's head)
    minCost[0][0] = 0;
    while (!pq.empty()) {
        vector<int> v = pq.top(); 
        int c = v[0], x = v[1], y = v[2];
        pq.pop();
        // cost to move right:
        if (y+1 < n+2 && x+1 < m) {
            // cout << "mving right" << endl;
            // mine right of head, mine right of feet
            int cost = c + grid[x][y+1] + grid[x+1][y+1];
            if (cost < minCost[x][y+1]) {
                minCost[x][y+1] = cost;
                pq.push({cost, x, y+1});
            }
        }
        // cost to move left, mine left of feet
        if (y-1 >= 0 && x+1 < m) {
            // cout << "mving left" << endl;
            int cost = c + grid[x][y-1] + grid[x+1][y-1];
            if (cost < minCost[x][y-1]) {
                minCost[x][y-1] = cost;
                pq.push({cost, x, y-1});
            }
        }
        // cost to move up
        if (x-1 >= 0) {
            // cout << "mving up" << endl;
            int newHead = x-1;
            int newCost = c + grid[newHead][y]; // only mine new head
            if (newCost < minCost[newHead][y]) {
                minCost[newHead][y] = newCost;
                pq.push({newCost, newHead, y});
            }
        }
        // cost to move down
        if (x+2 < m) {
            // cout << "mving down" << endl;
            int newHead = x+1;
            int newFeet = x+2;
            int newCost = c + grid[newFeet][y]; // only mine new feet
            if (newCost < minCost[newHead][y]) {
                minCost[newHead][y] = newCost;
                pq.push({newCost, newHead, y});
            }
        }
    }

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n+2; j++) {
    //         cout << minCost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << minCost[m-2][n+1] << endl;

    return 0;
}