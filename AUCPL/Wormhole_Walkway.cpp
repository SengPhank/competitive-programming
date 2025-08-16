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
    string tempS;
    for (int i = 0; i < numPpl; i++) {
        cin >> tempS;
        people[i] = tempS;
    }

    unordered_map<int, string> clean; // {node : people start}
    for (int i = 0; i < numPpl; i++) {
        cin >> temp;
        clean[temp] = people[i];
    }

    // loop through from exit
    queue<int> dfs;
    dfs.push(numRooms);

    unordered_set<string> winners;
    vector<string> b;
    while (!dfs.empty()) {
        int a = dfs.front();
        dfs.pop();
        for (int i : portal[a]) {
            if (clean.count(i)) {
                winners.insert(clean[i]);
                b.push_back(clean[i]);
            }
            dfs.push(i);
        }
    }
    // print winners
    for (string i : b) {
        cout << i << " ";
    }

    cout << endl;
    for (string i : people) {
        if (!(winners.count(i))) {
            cout << i << " ";
        }
    }

    return 0;
}