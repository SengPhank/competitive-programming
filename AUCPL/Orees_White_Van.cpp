#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numC;
    cin >> numC;
    vector<int> prefSums(numC);
    cin >> prefSums[0];
    for (int i = 1; i < numC; i++) {
        int tmp;
        cin >> tmp;
        prefSums[i] = tmp + prefSums[i-1];
    }
    int numQ;
    cin >> numQ;
    for (int i = 0; i < numQ; i++) {
        int l, r;
        cin >> l >> r;
        int s;
        if (l == 0) {
            s = prefSums[r];
        } else {
            s = prefSums[r] - prefSums[l-1];
        }
        if (s > 0) {
            cout << (s+10) << endl;
        } else if (s < 0) {
            cout << (s-10) << endl;
        } else {
            cout << (s+100) << endl;
        }
    }
    return 0;
}