/*
Problem Statement

Takahashi eats three plates for breakfast: rice, miso soup, and salad.

His table is long and narrow, so he arranged the three plates in a row. The arrangement is given by a string
S, where the i-th plate from the left is rice if Si​ is R, miso soup if Si​ is M, and salad if

Si​ is S.

Determine whether the plate of rice is to the left of the plate of miso soup.
Constraints

∣S∣=3
S contains one R, one M, and one S.
*/

#include <iostream>
#include <string>

int main(void) {
    std::string s; 
    std::cin >> s;
    int riceIndex = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            riceIndex = i;
        } else if (s[i] == 'M') {
            if (riceIndex == -1) {
                std::cout << "No" << std::endl;
            } else {
                std::cout << "Yes" << std::endl;
            }
            break;
        } 
    }
    return 0;
}