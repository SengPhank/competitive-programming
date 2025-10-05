#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> cans(n);
    map<int, int> ind;
    for (int i = 0; i < n; i++) {
        cin >> cans[i];
    }
    vector<int> sol(n);
    for (int i = n-1; i >= 0; i--) {
        ind[cans[i]] = (i+1); // 1-indexed
        auto curIt = ind.find(cans[i]);
        ++curIt;
        if (curIt != ind.end() && curIt->second > i) {
            sol[i] = curIt->first;
        } else {
            sol[i] = -1;
        }
    }

    for (int i : sol) {
        cout << i << endl;
    }

    return 0;
}