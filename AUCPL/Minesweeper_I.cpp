#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int main() {
    // Set bits = 1;
    // Find minimum set bits needed to traverse.

    pair<int, int> targetCoord, currentCoord = {0, 0};
    cin >> targetCoord.first >> targetCoord.second;

    int maxDanger = -2147483647;

    // Apply greedy algorithm?????
    while (currentCoord != targetCoord) {
        // Find the least risk out of moving x or y
        bitset<32> bitx(currentCoord.first ^ targetCoord.first);
        bitset<32> bity(currentCoord.second ^ targetCoord.second);
        int moveX = bitx.count();
        int moveY = bity.count();

        //cout << "Current (" << currentCoord.first << ", " << currentCoord.second << ")" << endl;
        if (moveX > moveY || (currentCoord.first == targetCoord.first && currentCoord.second != targetCoord.second)) { // moving x more dangerous than moving y, or can't move X anymore
            currentCoord.second++;
            
        } else {
            currentCoord.first++;
        }

        bitset<32> bitr(currentCoord.first ^ currentCoord.second);
        int currentRisk = bitr.count();
        //cout << currentCoord.first << " XOR " << currentCoord.second << " = " << currentRisk << endl;
        
        if (currentRisk > maxDanger) {
            maxDanger = currentRisk;
        }
    }

    cout << maxDanger << endl;

  
    return 0;
  }