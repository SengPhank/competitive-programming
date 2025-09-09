#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int numCase;
    cin >> numCase;
    vector<int> dp(numCase+1, 100000+1);
    dp[1] = 0;
    for (int i = 0; i < numCase; i++) {
        int a;
        cin >> a;
        dp[a-1] = min(dp[a-1]+1, dp[a]);
        if (a%2 == 0) {
            dp[a/2] = min(dp[a/2]+1, dp[a]);
        }
        if (a%2 == 0) {
            dp[a/2] = min(dp[a/2]+1, dp[a]);
        }
    
        cout << dp[a] << endl;
    }

    return 0;
}