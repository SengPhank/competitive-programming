#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int busR, busC;
    cin >> busR >> busC;

    int numZombies;
    cin >> numZombies;

    int minDist = INT_MAX;
    int tempR, tempC;
    for (int i = 0; i < numZombies; i++) {
        cin >> tempR >> tempC;
        if (abs(busR-tempR) + abs(busC-tempC) < minDist) {
            minDist = abs(tempR-busR) + abs(tempC-busC);
        }
    }

    if (abs(busR) + abs(busC) >= minDist) {
        cout << "Oh no! The zombies ate your brains!" << endl;
    } else {
        cout << "Yes! We did it!" << endl;
    }

    return 0;
}