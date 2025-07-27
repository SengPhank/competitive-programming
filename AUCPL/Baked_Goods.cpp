#include <iostream>
#include <stack>
#include <set>
#include <utility> // pair

// Incomplete

// find largest subarray within -5 and 5 of each and use max    
int main(void) {
    std::set<std::pair<int, int>> toBakeSet;
    std::stack<std::pair<int, int>> toBakeStack;
    int numBakes, h, t;
    std::cin >> numBakes;

    // convert to set to remove dupes and sort
    for (int i = 0; i < numBakes; i++) {
        std::cin >> h >> t;
        toBakeSet.insert({h, t});
    }
    // convert to stack
    for (std::pair<int, int> i : toBakeSet) { // Smallest Temp bottom, biggest top
        toBakeStack.push(i);
    }

    int minimumTime = 0;
    int cookingTemp = -1; // degrees (c or f idc)
    int initialTime = 0;

    while (!toBakeStack.empty()) {
        std::pair<int, int> bake = toBakeStack.top();

        std::cout << "Current Temperature: " << bake.first << std::endl;
        
        // check in range, or changable.
        if (cookingTemp == -1) { // On first cook
            std::cout << "Initial cooking temperature: " << bake.first << std::endl;
            cookingTemp = bake.first-5;
            initialTime = bake.second;
            toBakeStack.pop();       
            continue;
        }

        // In range
        if (bake.first <= cookingTemp+5 && bake.first >= cookingTemp-5) {
            bake.second -= initialTime;
            if (bake.second <= 0) {
                toBakeStack.pop();
            }
        } else { // Out of range, get highest Time there and reset all stats
            std::cout << "Temperature not between " << cookingTemp-5 << " and " << cookingTemp+5 << std::endl;
            minimumTime += currentMaxTime;
            std::cout << "adding time: " << currentMaxTime << std::endl;
            cookingTemp = -1;
            currentMaxTime = 0;
            continue;
        }
        
    }

    minimumTime += currentMaxTime;
    std::cout << minimumTime << std::endl;
    // On exit, get final highest time and return
}

/*t1 
3
160 20
165 40
175 35

expected:
55
*/

/*t2
4
171 1
172 2
173 3
176 1

expected:
4
*/

/*t3
6
179 5 
180 10 
180 12
185 9 
190 10
191 3

expected:
15
*/

/*t4
7
*/