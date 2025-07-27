#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(void) {
    int votes;
    unordered_map<string, int> poll;

    cin >> votes;
    for (int i = 0; i < votes; i++) {
        string temp;

        cin >> temp;
        poll[temp] += 1;
    }

    string Winner;
    int maxVotes = -INFINITY;
    for (auto i : poll) {
        if (i.second > maxVotes) {
            maxVotes = i.second;
            Winner = i.first;
        } else if (i.second == maxVotes) {
            if (i.first.length() < Winner.length()) {
                Winner = i.first;
            }
        }
    }

    cout << Winner << endl;
    return 0;
}