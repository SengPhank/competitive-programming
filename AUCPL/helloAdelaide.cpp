#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numPeople;
    vector<string> peopleArry;
    cin >> numPeople;

    for (int i = 0; i < numPeople; i++) {
        string tempLine;

        cin >> tempLine;
        peopleArry.push_back(tempLine);
    }

    for (auto i : peopleArry) {
        cout << "Hello " << i << "!" << endl;
    }

    return 0;
}