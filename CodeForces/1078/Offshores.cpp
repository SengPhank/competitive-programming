#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // must have exactly x credits to transfer
    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        long long totalSum = 0;
        vector<long long> banks(n);
        vector<long long> bankFee(n);
        for (int b = 0; b < n; b++) {
            cin >> banks[b];
            bankFee[b] = (banks[b] / x) * y;
            totalSum += bankFee[b];
        }
        long long sol = 0;
        for (int i = 0; i < n; i++) {
            sol = max(sol, banks[i] + totalSum - bankFee[i]);
        }
        cout << sol << endl;
        
    }
}

// (45, 44) -> (55, 29) -> (65, 14)
// (30, 54) -> (15, 64) -> (0, 74);