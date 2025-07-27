#include <bits/stdc++.h>
#include <map>
using namespace std;

// Memory limit exeded
unsigned int recursive(unsigned int n, map<unsigned int, unsigned int>& memoisation) {
    if (memoisation.find(n) != memoisation.end()) {
        return memoisation[n];
    }
    unsigned int res = recursive(n-1, memoisation)^n;
    memoisation[n] = res;
    return res;
}
int main(void) {
    map<unsigned int, unsigned int> memoisation = {
        {1, 0},
        {2, 3}};
    
    unsigned int l, r, sum = 0;
    cin >> l >> r;
    for (unsigned int i = l; i <= r; i++) {
        sum += recursive(i, memoisation);
    }

    cout << sum << endl;
    return 0;
}