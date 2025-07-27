#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(void) {
    int num, denom;
    cin >> num >> denom;

    float ans = (float) num/denom;
    float decimal = (float) (num%denom)/denom;
    //cout << "Number float: " << ans << ", decimal: " << decimal << endl;
    
    if (ans == (int) ans) {
        cout << (int) ans << endl;
    } else if (decimal < 0.5) {
        cout << floor(ans) << endl;
    } else {
        cout << ceil(ans) << endl;
    }

    return 0;
}