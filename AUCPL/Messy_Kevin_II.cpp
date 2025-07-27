#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(void) {
    int nums;
    cin >> nums;
    cin.ignore();

    map<string, int> messages;
    for (int i = 0; i < nums; i++) {
        string s;
        getline(cin, s);
        messages[s] += 1;
    }

    for (auto i : messages) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;

}