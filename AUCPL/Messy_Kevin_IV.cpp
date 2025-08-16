#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a = 0, temp;
    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        a += temp;
    }

    int b = 0;
    for (int i = 1; i <= n; i++) {
        b += i;
    }

    cout << b-a << endl;
    return 0;
}