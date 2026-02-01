#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int numCase;
    cin >> numCase;
    for (int k = 0; k < numCase; k++) {
        int hp;
        cin >> hp;
        vector<int> dp(hp+1, INT_MAX);
        dp[hp] = 0;
        for (int i = hp-1; i >= 0; i--) {
            dp[i] = min(dp[i], dp[i+1]+1);
            if (i*3 <= hp) dp[i] = min(dp[i], dp[i*3]+1); 
            if (i*2 <= hp) dp[i] = min(dp[i], dp[i*2]+1); 
        }

        // for (int i = hp; i >= 0; i--) {
        //     cout << "costs " << dp[i] << " to get down to hp " << i << endl;
        // }
        cout << dp[1] << endl;
    }

    return 0;
}
// 5 - > -1 = 4,
