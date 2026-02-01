#include <bits/stdc++.h>
using namespace std;

void op(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    op();
    int n, v;
    cin >> n >> v;
    long long maxGrid = INT_MIN;
    vector<long long> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        maxGrid = max(maxGrid, grid[i]);
    }

    long long sol = 0;
    long long curFree = 0;
    for (int i = 0; i < n; i++) {
        if (grid[i] == maxGrid) {
            sol += curFree / v;
            curFree = 0;
        } else {
            curFree += maxGrid - grid[i];
        }
    }

    sol += curFree / v;
    cout << sol << endl;
    return 0;


}