#include <iostream>
#include <map>
#include <utility>
// Incomplete

// find largest subarray within -5 and 5 of each and use max    
int main(void) {
    std::cout<<"a"<<std::endl;
    int numBakes;
    std::cin >> numBakes;
    // find max time, group by max time
    std::map<int, std::pair<int, int>> pq;

    int h, t;
    for (int i = 0; i < numBakes; i++) {
        std::cin >> h >> t;
        pq.push({h, t});
    }

    // find lowest temp to cook
    int curTemp, curMaxTime;
    int maxOveralTime = 0;
    //std::cout << "calculating..." << std::endl;
    while (!pq.empty()) {
        curTemp = pq.top().first - 5; // can cook within a 5c range, so use that
        curMaxTime = pq.top().second; // find maximum time withinn cooking range
        std::cout << "cooking time: " << curTemp << std::endl;
        while (!pq.empty() && pq.top().first >= curTemp-5 && pq.top().first <= curTemp+5) {
            if (pq.top().second > curMaxTime) {
                pq.top().second -= curMaxTime;
            }
            std::cout << "cooked t: " << pq.top().first << ", minute: " << pq.top().second << std::endl;
            pq.pop();
        }

        maxOveralTime += curMaxTime;
    }

    std::cout << maxOveralTime << std::endl;
    return 0;
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