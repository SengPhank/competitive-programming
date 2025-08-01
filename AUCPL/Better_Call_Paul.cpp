// https://aucpl.com/problem/bettercallpaul
#include <iostream>
#include <vector>
int main(void) {
    int numCols;
    std::cin >> numCols;

    std::vector<int> cols(numCols); 
    double maxScore = 0;
    int colRes;

    // insertion
    double temp;
    for (int i = 0; i < numCols; i++) {
        std::cin >> temp;
        cols[i] = temp;
    }

    // extreme left
    maxScore = ((double)cols[0] * 0.75) + ((double)cols[1] * 0.25);
    colRes = 0;

    // check for extreme right
    temp = ((double)cols[numCols-1] * 0.75) + ((double)cols[numCols-2] * 0.25);
    if (temp > maxScore) {
        maxScore = temp;
        colRes = numCols-1;
    }

    for (int i = 1; i < numCols-1; i++) {
        temp = ((double)cols[i-1] * 0.25) + ((double)cols[i] * 0.5) + ((double)cols[i+1] * 0.25);
        if (temp > maxScore) {
            maxScore = temp;
            colRes = i;
        }
    }

    // std::cout << "max winnings: " << maxScore << std::endl;
    std::cout << colRes << std::endl;

    return 0;
}

/*t1
6
3 -1 2 7 -4 5

e:
3*/

/*t2
3
1 3 -1

3: 
0 || 1
*/