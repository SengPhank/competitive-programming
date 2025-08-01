#include <iostream>

// Global variable
int overalMin = __INT_MAX__;

void dfsMap(const int& tX, const int& tY, int x, int y, int minDanger) {
    std::cout << x << " XOR " << y << " = " << (x^y) << std::endl; 
    if ((x^y) > minDanger) { // determine risk
        minDanger = (x^y);
    }
    if (x == tX && y == tY) {
        if (minDanger < overalMin) {
            overalMin = minDanger;
        }
        return;
    }
    // move right (if possible)
    if (x < tX) {
        dfsMap(tX, tY, x+1, y, minDanger);
    }
    // move down (if possible)
    if (y < tY) {
        dfsMap(tX, tY, x, y+1, minDanger);
    }
}

int main() {
    int targetX, targetY;
    std::cin >> targetX >> targetY;

    dfsMap(targetX, targetY, 0, 0, 0);
    std::cout << overalMin << std::endl;
    return 0;
}