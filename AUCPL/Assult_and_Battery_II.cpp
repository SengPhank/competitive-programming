#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

// INCOMPLETE 
int main(void) {
    int numBatteries;   
    std::cin >> numBatteries;
    // T : {p, n}
    std::unordered_map<int, int> batMap;

    // closest Xa - Na candidates
    std::vector<std::pair<int, int>> pBatteries;
    // closest Xb - Nb candidates
    std::vector<std::pair<int, int>> nBatteries;

    // insert
    int t, p, n;
    for (int i = 0; i < numBatteries; i++) {
        std::cin >> t >> p >> n;
        batMap[t] = {p, n};
    }

    int minimumValue = __INT_MAX__;
    // find closest Xa - Na Candidates and Xb - Nb candidates


    return 0;
}
