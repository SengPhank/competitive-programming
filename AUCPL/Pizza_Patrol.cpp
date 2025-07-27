#include <bits/stdc++.h>
#include <set>

int main(void) {
    int numExist, x;
    std::cin >> numExist;

    // Insert law-abiding citizens
    std::set<int> line;
    for (int i = 0; i < numExist; i++) {
        std::cin >> x;
        line.insert(x);
    }
    
    // Find cutters
    int numCuts;
    std::cin >> numCuts;

    for (int i = 0; i < numCuts; i++) {
        std::cin >> x;
        auto it = line.insert(x);
        if (it.second && std::next(it.first) != line.end()) { // if successfully inserted and there is someone infront of them 
            std::cout << "A greedy member at " << x << " has pushed in front of the member at " << *std::next(it.first) << ", this is terrible" << std::endl;
        }
    }

    return 0;
}

/* t1: 
4
1 4 6 8
6
0 2 4 5 10 9

expected:
A greedy member at 0 has pushed in front of the member at 1, this is terrible
A greedy member at 2 has pushed in front of the member at 4, this is terrible
A greedy member at 5 has pushed in front of the member at 6, this is terrible
A greedy member at 9 has pushed in front of the member at 10, this is terrible
*/

/* t2: 
1
3
1
2

expected:
A greedy member at 2 has pushed in front of the member at 3, this is terrible
*/

/* t3: 
7 
4 5 6 8 9 10 14
4
2 3 0 12

expected:
A greedy member at 2 has pushed in front of the member at 4, this is terrible
A greedy member at 3 has pushed in front of the member at 4, this is terrible
A greedy member at 0 has pushed in front of the member at 2, this is terrible
A greedy member at 12 has pushed in front of the member at 14, this is terrible
*/