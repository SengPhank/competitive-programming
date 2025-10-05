#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numDrinks;
    cin >> numDrinks;
    vector<int> drinks(numDrinks);

    for (int i = 0; i < numDrinks; i++) {
        cin >> drinks[i];
    }

    int target;
    cin >> target;


    vector<unsigned long long> dp(target+1, 0);
    dp[0] = 1;

    for (int d : drinks) {
        for (int i = 0; i <= target; i++) {
            if (i+d <= target) 
                dp[i+d] += dp[i];
        }
    }
    cout << dp[target] << endl;

    return 0;
}