#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string name;
    int handi, score;

    map<int, vector<string>> scoreBoard;
    while (1) {
        cin >> name >> handi >> score;
        if (name == "X") { break; }
        scoreBoard[score-handi].push_back(name);
    }

    for (auto it : scoreBoard) {
        for (string name : it.second) {
            cout << name << " " << it.first << endl;
        }
    }

    return 0;


}