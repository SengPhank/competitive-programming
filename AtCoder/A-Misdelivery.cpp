#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int nums;
    cin >> nums;
    vector<string> room(nums);

    for (int i = 0; i < nums; i++) {
        string s;
        cin >> room[i];
    }

    int tR;
    string tS;
    cin >> tR >> tS;
    if (room[tR-1] == tS) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}