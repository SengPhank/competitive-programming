#include <iostream>
#include <unordered_map>
#include <set>

int main(void) {
    int numBatteries;   
    bool breakEarly = false;
    std::cin >> numBatteries;

    std::unordered_map<int, std::set<int>> batMap; // battery map = { batteryType, [charge1, chargen] }
    int x, y;
    for (int i = 0; i < numBatteries; i++) {
        std::cin >> x >> y; // battery type >> battery charge
        if (!batMap[x].insert(y).second) { // if the same battery type already has a the same charge, return and end (as 0 is the minimum score)
            std::cout << "breaking early, look type: " << x << std::endl;
            breakEarly = true;
        }
    }

    if (breakEarly) {
        std::cout << "0" << std::endl;
        return 0;
    }

    int lowestScore = __INT_MAX__;
    int prevCharge;
    for (auto batteries : batMap) {
        prevCharge = -1;
        // std::cout << "battery type: " << batteries.first << " db: " << batteries.second.size() << std::endl;

        for (int charge : batteries.second) {
            if (prevCharge == -1) {  // on first element, skip
                prevCharge = charge;
                continue; 
            }
            // std::cout << "comparing prev charge: " << charge << " to current: " << prevCharge << std::endl;
            if (charge - prevCharge < lowestScore) {
                lowestScore = charge - prevCharge;
            }
            prevCharge = charge;
        }
    }

    if (lowestScore == __INT_MAX__) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << lowestScore << std::endl;
    }

    return 0;

}
