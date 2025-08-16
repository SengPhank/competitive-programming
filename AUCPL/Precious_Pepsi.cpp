#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m, n; // r, c
    cin >> m >> n;

    vector<string> board(m);
    int startR = -1, startC = -1;
    int pepR = -1, pepC = -1;

    // store input
    string a;
    for (int i = 0; i < m; i++) {
        cin >> a;
        board[i] = a;
    }

    // find start and end location
    for (int i = 0; i < m; i++) {
        if (pepR != -1 && startR != -1) { break; }
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'p') {
                pepR = i;
                pepC = j;
            } else if (board[i][j] == '@') {
                startR = i;
                startC = j;
            }
        }
    }

    // visited
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    // bfs
    queue<tuple<int, int, int>> bfs; // {r, c, step}

    bfs.push({startR, startC, 0});
    while (!bfs.empty()) {
        auto [r, c, step] = bfs.front();

        bfs.pop();
        if (r == pepR && c == pepC) {
            cout << step << endl;
            return 0;
        }
        
        // atempt to move left (check in-bounds and unexplorable/not a wall)
        if (c-1 >= 0 && !visited[r][c-1] && board[r][c-1] != '#') {
            bfs.push({r, c-1, step+1});
            visited[r][c-1] = true;
        }

        // atempt to move right (check in-bounds and unexplorable/not a wall)
        if (c+1 < n && !visited[r][c+1] && board[r][c+1] != '#') {
            bfs.push({r, c+1, step+1});
            visited[r][c+1] = true;
        }

        // atempt to move down (check in-bounds and unexplorable/not a wall)
        if (r-1 >= 0 && !visited[r-1][c] && board[r-1][c] != '#') {
            bfs.push({r-1, c, step+1});
            visited[r-1][c] = true;
        }

        // atempt to move up (check in-bounds and unexplorable/not a wall)
        if (r+1 < m && !visited[r+1][c] && board[r+1][c] != '#') {
            bfs.push({r+1, c, step+1});
            visited[r+1][c] = true;
        }
    }

    cout << -1 << endl;
    
    return 0;
}