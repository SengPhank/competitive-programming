#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numCoins;
    map<int, int> setGroup; // max value, group

    int maxNum = -2147483647;
    cin >> numCoins;
    for (int i = 0; i < numCoins; i++) {
        int p, s, c;
        cin >> p >> s >> c;

        int sum = (p * 20 * 12) + (s * 12) + c;
        setGroup[sum] += 1;

        if (sum > maxNum) {
            maxNum = sum;
        }
    }

    cout << setGroup[maxNum] << endl;
}