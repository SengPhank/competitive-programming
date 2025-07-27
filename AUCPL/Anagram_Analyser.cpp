#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(void) {
    int nums;
    cin >> nums;
    map<map<char, int>, vector<string>> lenMap;
    vector<set<string>> anaGroup; 

    for (int i = 0; i < nums; i++) {
        string s;
        cin >> s;
        
        map<char, int> temp;
        for (auto i : s) {
            temp[i] += i;
        }
        
        lenMap[temp].push_back(s);
    }

    cout << lenMap.size() << endl;
    return 0;
}