#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numC, target;
    cin >> numC >> target;
    vector<int> candies(numC);
    vector<int> dp(target+1, target+1);
    dp[0] = 0;

    // insert candie
    for (int i = 0; i < numC; i++) {
        cin >> candies[i];
    }

    for (int i = 1; i <= target; i++) {
        for (int c : candies) {
            if (i-c >= 0) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    if (dp[target] == target+1) {
        cout << -1 << endl; 
    } else {
        cout << dp[target] << endl;
    }
    return 0;
}