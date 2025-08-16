#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numRooms, numPpl;
    cin >> numRooms >> numPpl;

    unordered_map<int, vector<int>> portal;
    // room i is a parent of {rooms};
    int temp;
    for (int i = 1; i <= numRooms-1; i++) {
        cin >> temp;
        portal[temp].push_back(i);
    }
    
    vector<string> people(numPpl);
    unordered_map<string, int> peopleOrder;
    string tempS;
    for (int i = 0; i < numPpl; i++) {
        cin >> tempS;
        people[i] = tempS;
        peopleOrder[tempS] = i;
    }

    unordered_map<int, vector<string>> clean; // {node : people start}
    for (int i = 0; i < numPpl; i++) {
        cin >> temp;
        clean[temp].push_back(people[i]);
    }

    // loop through from exit using bfs
    queue<pair<int, int>> dfs; // {node, 'distance' from exit}
    dfs.push({numRooms, 0});

    unordered_set<string> winners;
    vector<pair<string, int>> wins; // sorted by time, then name

    while (!dfs.empty()) {
        auto [a, b] = dfs.front();
        dfs.pop();
        for (int i : portal[a]) {
            if (clean.count(i)) {
                for (string s : clean[i]) {
                    winners.insert(s);
                    wins.push_back({s, b});
                }
                
            }
            dfs.push({i, b + 1});
        }
    }
    sort(wins.begin(), wins.end(), [&](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) {
            // Sort by peopleOrder when timestamps are equal
            return peopleOrder[a.first] < peopleOrder[b.first];
        } else {
            // Otherwise, sort by time
            return a.second < b.second;
        }
    });
    // print winners
    for (auto s : wins) {
        cout << s.first << " ";
    }
    cout << endl;

    // print losers
    for (string i : people) {
        if (!(winners.count(i))) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}