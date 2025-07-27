#include <bits/stdc++.h>
#include <math.h>
#include <set>
using namespace std;

// Not disjoint event (A and B can occur at the same time)
// P( A or B ) = P (A) + P (B) - P(A and B)

int main(void) {
    int sumLeastX, absDiffY;
    cin >> sumLeastX >> absDiffY;
    set<pair<int, int>> ans;

    int iter = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if ((i + j) >= sumLeastX) {
                auto res = ans.insert({i, j});
                if (res.second) { // successful insert
                    iter++;
                }
            } 
            if (abs(i - j) >= absDiffY) {
                auto res = ans.insert({i, j});
                if (res.second) { // successful insert
                    iter++;
                }
            }
        }
    }

    double AorB = (double) iter/36;
    cout << fixed << setprecision(10) << AorB << endl;
    return 0;
}