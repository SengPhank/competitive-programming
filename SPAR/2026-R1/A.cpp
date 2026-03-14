#include <bits/stdc++.h>
using namespace std;

// INCORRECT/INCOMPLETE
void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int findOct(int n, int l, int h) {
    /*
    n - 12x = h, 
    12x = n-h, 
    x = (n-h)/12
    */
    if (n >= l && n <= h) return 0;
    if (n >= h) return ((n-h)/12) - 1;
    if (n <= l) return ((n-l)/12) + 1;
    return 0;
}
int main(void) {
    f();    
    // shortest interval longest difference
    int n, l, h;
    cin >> n >> l >> h;
    int sol = 0;
    
    int prevOct = INT_MIN;
    int lo = INT_MAX, hi = INT_MIN;
    int cSize = 0;
    int prevDiff = INT_MAX, prevSize = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        int oct = findOct(tmp, l, h);
        cout << "oct: " << oct << endl;
        if (oct == prevOct) {
            // same group
            lo = min(lo, tmp), hi = max(hi, tmp);
            cSize++;
        } else {
            int diff = hi-lo;
            // shortest interval
            if (diff < prevDiff) {
                prevDiff = diff;
                prevSize = cSize;
            } else if (diff == prevDiff) {
                // maximum length
                prevSize = max(prevSize, cSize);
            }
            // reset init
            lo = tmp, hi = tmp;
            cSize = 1;
        }
        prevOct = oct;
        cout << lo << ", " << hi << ", " << cSize << ", " << prevDiff << endl;
    }
    // final check
    int diff = hi-lo;
    // shortest interval
    if (diff < prevDiff) {
        prevDiff = diff;
        prevSize = cSize;
    } else if (diff == prevDiff) {
        // maximum length
        prevSize = max(prevSize, cSize);
    }

    cout << prevSize << endl;
    
    return 0;
}