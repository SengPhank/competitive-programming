#include <bits/stdc++.h>
#include <set>
using namespace std;

int solve(set<char> availableLetters, vector<string> teamInfo) {
    int ans = 0;
    bool isSuccess;
    set<char> toErase = availableLetters;
    for (string i : teamInfo) {
        isSuccess = true;
        for (char j : i) {
            if ((toErase.find(j) != toErase.end())) { // If j in available letters
                toErase.erase(j);
            } else {
                isSuccess = false;
                break;
            }
        }

        if (isSuccess) {
            availableLetters = toErase;
            ans += 1;
        }

        toErase = availableLetters; // reset 
    }

    return ans;
}
// INCORR
int main(void) {
    int numProblems, numTeams;
    set<char> availableLetters;
    vector<string> teamInfo;

    cin >> numProblems >> numTeams;

    // Init available letters
    for (int i = 65; i < (65 + numProblems); i++) { 
        availableLetters.insert(i);
    }   

    // Sort Team NAMES by length
    for (int i = 0; i < numTeams; i++) {
        string team;
        cin >> team;
        teamInfo.push_back(team);
    }

    sort(teamInfo.begin(), teamInfo.end(), [](string a, string b){
        return a.size() < b.size();
    });
    int ans1 = solve(availableLetters, teamInfo);

    sort(teamInfo.begin(), teamInfo.end(), [](string a, string b){
        return a.size() > b.size();
    });
    int ans2 = solve(availableLetters, teamInfo);


    if (ans1 > ans2) {
        cout << ans1 << endl;
        return 0;
    } 
    cout << ans2 << endl;
    return 0;
}