#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

void to_lower(string& s) {
    if (s[0] >= 'A' && s[0] <= 'Z') s[0] += 32;
}
int main(void) {
    f();    
    int n;
    cin >> n;
    // greedy, tkae the smallest section of each player's name
    vector<string> sol;
    int parts;
    bool val = true;
    string prev, tmp;

    // initial
    cin >> parts >> prev;
    to_lower(prev);
    for (int i = 1; i < parts; i++) {
        cin >> tmp;
        to_lower(tmp);
        if (tmp < prev) prev = tmp; 
    }
    sol.push_back(prev);

    for (int i = 1; i < n; i++) {
        if (!val) break;
        string name;
        cin >> parts >> name;
        to_lower(name);
        for (int j = 1; j < parts; j++) {
            cin >> tmp;
            to_lower(tmp);
            if (name < prev || (tmp >= prev && tmp < name)) name = tmp;
        }
        if (name < prev) val = false;
        prev = name;
        sol.push_back(name);
    }

    if (val) {
        for (string& i : sol) {
            i[0] -= 32;
            cout << i << "\n";
        }
    } else {
        cout << "impossible";
    }
    return 0;
}