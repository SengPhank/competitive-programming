#include <bits/stdc++.h>
using namespace std;

// UNFINISHED
bool checkSurrounding(char map2D[][], int posX, int posY) {
    // Check top
    for (int i = 1; i <= 3) {
        if (posY - 1 < 1) {
            break;
        }
        if (map2D[posX - i][posY - 1]) {

        }
    }

    return true;
}
int main(void) {
    int r, c;
    
    cin >> r >> c;
    char map2D[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char temp;
            map2D[i][j] = temp;
        }
    }
}