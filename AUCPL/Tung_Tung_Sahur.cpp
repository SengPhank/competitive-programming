#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numCards;
    cin >> numCards;
    stack<int> tmp;
    int current = 1;
    for (int i = 0; i < numCards; i++) {
        int a;
        cin >> a;
        // check side stack
        while (!tmp.empty() && tmp.top() == current) {
            current++;
            tmp.pop();
        }
        if (a == current) {
            current++;
            // check side stack again
            while (!tmp.empty() && tmp.top() == current) {
                current++;
                tmp.pop();
            }
        } else {
            tmp.push(a);
        }
    }

    if (tmp.empty()) {
        cout << "Tung Tung Tung" << endl;
    } else {
        cout << "Mamma Mia!" << endl;
    }

    return 0;
}