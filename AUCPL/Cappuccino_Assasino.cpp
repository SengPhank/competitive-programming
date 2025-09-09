#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numDoms; 
    cin >> numDoms;
    int longstStreak = 0;
    int curStreak = 1;
    int prev;
    cin >> prev;
    for (int i = 1; i < numDoms; i++) {
        int a; 
        cin >> a;
        if (prev > a) {
            curStreak++;
        } else {
            longstStreak = max(longstStreak, curStreak);
            curStreak = 1;
        }
        prev = a;
    }
    longstStreak = max(longstStreak, curStreak);

    cout << longstStreak << endl;

    return 0;

}