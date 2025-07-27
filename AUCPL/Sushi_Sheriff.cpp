#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int numQ;
    cin >> numQ;

    unordered_set<string> uniqueQ;
    for (int i = 0; i < numQ; i++) {
        string name;
        cin >> name;
        if (uniqueQ.find(name) != uniqueQ.end()) {
            cout << name << endl;
        } else {
            uniqueQ.insert(name);
        }
        
    }
    return 0;
}