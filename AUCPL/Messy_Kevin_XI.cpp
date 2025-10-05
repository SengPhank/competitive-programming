#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int curEnergy = 0;
    /*
    If Kevin never becomes grumpy, output his final energy level.
    If he becomes grumpy at any point, output the energy level when he first became grumpy.
    */

    int first = 0;
    bool swi = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char t;
        int c;
        cin >> t >> c;

        switch (t)
        {
        case 'B':
            curEnergy += c;
            break;
        case 'C':
            curEnergy += c * 2;
            break;
        case 'W': 
            curEnergy -= c;
            if (curEnergy < 0) {
                if (swi) {
                    first = curEnergy;
                    swi = false;
                }
            }
            break;
        default:
            break;
        }
    }

    if (swi) {
        cout << curEnergy << endl;
    } else {
        cout << first << endl;
    }

    return 0;
}