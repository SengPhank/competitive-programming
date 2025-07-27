#include <bits/stdc++.h>
#include <map>
using namespace std;

int sortMe(vector<int> roundParam, vector<int> timeParam) {
    for (int i = 0; i < size(roundParam); i++) {
        if roundParam[i] < 
    }
}

int main(void) {
    int numTeams, roundParticipated;
    map<string, vector<int>> teamInfo; // teamName: [total best 6 rounds, total lowest 6 time]
    // Sort by the high-low rounds, sort by low-high time
    
    string winnerName;
    int highestRound = 0, lowestTime = 2147483647; // Infinity

    cin >> numTeams;
    for (int i = 0;  i < numTeams; i++) {
        string teamName;
        cin >> teamName;

        int roundsPlayed;
        cin >> roundsPlayed;

        vector<int> tempRounds, tempTime;
        for(int i = 0; i < roundsPlayed; i++) {
            int x, y;
            cin >> x >> y;

            tempRounds.push_back(x);
            tempTime.push_back(y);
        }

        for (auto i: tempRounds) {

        }

    }

    

    // Loop through the map
    for (const auto& entry : teamInfo) {
        
        if (entry.second[1] > highestRound) {
            winnerName = entry.first;
        } else if (entry.second[1] == highestRound) {
            if (entry.second[2] < lowestTime) {
                winnerName = entry.first;
            }
        }

    }

    cout << winnerName << endl;
    
    return 0;
}