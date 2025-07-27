#include <bits/stdc++.h>
#include <map>

int main(void) {
    unsigned int numWinnings;
    std::unordered_map<long, unsigned int> winnings; // {number : firstOccurence}
    std::cin >> numWinnings;

    // store winning numbers
    long x; 
    for (unsigned int i = 0; i < numWinnings; i++) {
        std::cin >> x;
        // On non-exists
        if (winnings.find(x) == winnings.end()) { 
            winnings[x] = i+1; // + 1 to account for 1-indexed
        }
    }

    // store bought tickets and winnings
    unsigned int numTickets;
    long profit = 0; // account for ticket prices;
    std::cin >> numTickets;

    for (unsigned int i = 0; i < numTickets; i++) {
        std::cin >> x;
        // winning ticket found
        if (winnings.find(x) != winnings.end()) {
            profit += winnings[x]; 
        }
    }
    profit -= (numTickets * 5);
    std::cout << profit << std::endl;

    return 0;

}