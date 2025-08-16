#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    int startR, startC;
    int pepR, pepC;

    string a;
    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < n; j++) {
            if (a[j] == 'p') {
                pepR = i;
                pepC = j;
            } else if (a[j] == '@') {
                startR = i;
                startC = j;
            }
            cout << "char: " << a[j] << " ";
            board[i][j] = a[j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    // bfs
    queue<tuple<int, int, int>> bfs; // {r, c, step}
    bfs.push({startR, startC, 0});

    tuple<int, int, int> current;
    while (!bfs.empty()) {
        current = bfs.front();
        if 
        bfs.pop();
        // atempt to move left (check in-bounds and unexplorable/not a wall)
        if (get<1>(current)-1 >= 0 && board[get<0>(current)][get<1>(current)-1] != 'p'
        && board[get<0>(current)][get<1>(current)-1] != '#') {
            
        }
    }

    
    return 0;
}