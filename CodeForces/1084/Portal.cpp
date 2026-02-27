#include <bits/stdc++.h>
using namespace std;

// NOT COMPLETE
void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

// can only move left/right, find the lexicographically smallest
void smallest_rotation(vector<int>& v) {
    // monotonic stack?
    for (int i = 0; i < v.size(); i++) {

    }
}

int main(void) {
    f();
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> out, in;
        bool outer = true;
        // store the outter/inner portals seperately
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (i == x || i == y) outer = !outer;
            if (outer) {
                out.push_back(tmp);
            } else {
                in.push_back(tmp);
            }
            // work on each array's lexicographically smallest independely
            smallest_rotation(out);
            smallest_rotation(in);
        }
        // print result
        cout << out.size() << ", " << in.size() << endl;
        outer = true;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i == x || i == y) outer = !outer;
            if (outer) {
                cout << out[a++] << " ";
            } else {
                cout << in[b++] << " ";
            }
        }
        cout << "\n";
    }
}

/*
4 O 2 1 O 5 7
The outter arrays (outside of portal) are independet from the inside array

// 3142, x = 0, y =4


12114211137
121 -> 211-> 112
*/