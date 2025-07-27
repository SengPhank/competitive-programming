#include <bits/stdc++.h>
using namespace std;

    int main(void) {
        int numClues;
        vector<int> numGuess(100);
        iota(numGuess.begin(), numGuess.end(), 1); // Fill vector 1-100

        cin >> numClues;
        for (int i = 0; i < numClues; i++) {
            int divisible;
            string yesNo;

            vector<int> temp;
            cin >> divisible >> yesNo;
            if (yesNo == "Yes") {
                for (int j = 0; j < numGuess.size(); j++) {
                    if ((numGuess[j] % divisible) == 0) {
                        temp.push_back(numGuess[j]);
                    }
                }
            } else {
                for (int j = 0; j < numGuess.size(); j++) {
                    if ((numGuess[j] % divisible) != 0) {
                        temp.push_back(numGuess[j]);
                    }
                }
            }

        numGuess = temp;
    }

    cout << numGuess[0] << endl;

    return 0;
}