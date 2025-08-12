#include <bits/stdc++.h>
using namespace std;

// GLOBAL
int minPositions = INT_MAX;

void eliminateIsland(vector<vector<char>>& mapGrid, int r, int c) {
    mapGrid[r][c] = '.';
    // checking up
    for (int i = 0; i < r; i++) {
        if (mapGrid[i][c] == '#') {
            mapGrid[i][c] = '.';
        }
    }
    // checking down
    for (int i = r+1; i < 15; i++) {
        if (mapGrid[i][c] == '#') {
            mapGrid[i][c] = '.';
        }
    }
    // checking left
    for (int i = 0; i < c; i++) {
        if (mapGrid[r][i] == '#') {
            mapGrid[r][i] = '.';
        }
    } 

    // checking right
    for (int i = c+1; i < 15; i++) {
        if (mapGrid[r][i] == '#') {
            mapGrid[r][i] = '.';
        }
    }
}

// return nums island touching
int islandTouch(const vector<vector<char>>& mapGrid, int r, int c) {
    int count = 0;
    if (mapGrid[r][c] == '#') { count++; }
    // checking up
    for (int i = 0; i < r; i++) {
        if (mapGrid[i][c] == '#') {
            count++;
        }
    }
    // checking down
    for (int i = r+1; i < 15; i++) {
        if (mapGrid[i][c] == '#') {
            count++;
        }
    }
    // checking left
    for (int i = 0; i < c; i++) {
        if (mapGrid[r][i] == '#') {
            count++;
        }
    }
    // checking right
    for (int i = c+1; i < 15; i++) {
        if (mapGrid[r][i] == '#') {
            count++;
        }
    }
    return count;
}

pair<int, int> checkMax(vector<vector<char>> mapGrid, int tCounter, int max, int r, int c) {
    int x, y, temp;
    // int max = 0; // max islands on row/columns
    for (r; r < 15; r++) {
        for (c; c < 15; c++) {
            temp = islandTouch(mapGrid, r, c);
            if (temp > max) {
                x = r;
                y = c;
                max = temp;
            } else if (temp == max) { // split possibility with dfs
                pair<int, int> coords;
                int tCounter2 = tCounter;
                while (1) {
                    coords = checkMax(mapGrid, tCounter, max, r+1, c+1);
                    if (coords.first == -1 || coords.second == -1) {
                        if (tCounter2 < minPositions) {
                            minPositions = tCounter2;
                        }
                        break;
                    }
                    eliminateIsland(mapGrid, r, c);
                    tCounter2++;
                }
            }
        }
    }

    if (max == 0) {
        return {-1, -1};
    }
    return {x, y};
}

int main(void) {

    char temp;
    vector<vector<char>> mapGrid(15, std::vector<char>(15));
    for (int r = 0; r < 15; r++) {
        for (int c = 0; c < 15; c++) {
            cin >> temp;
            mapGrid[r][c] = temp;
        }
    }
    pair<int, int> coords;
    int tCounter = 0;
    while (1) {
        coords = checkMax(mapGrid, tCounter, 0, 0, 0);
        if (coords.first == -1 || coords.second == -1) {
            break;
        }
        eliminateIsland(mapGrid, coords.first, coords.second);
        tCounter++;
    }

    if (tCounter < minPositions) {
        minPositions = tCounter;
    }

    cout << minPositions << endl;
    return 0;
}