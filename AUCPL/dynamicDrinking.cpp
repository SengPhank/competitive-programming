#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int menuNum;
    vector<int> menuCost;
    vector<string> menuName;

    cin >> menuNum;

    // Take Input
    for (int i = 0; i < menuNum; i++) {
        int costTemp;
        string nameTemp;

        cin >> costTemp;
        cin >> nameTemp;

        menuCost.push_back(costTemp);
        menuName.push_back(nameTemp);
    }

    // Calculate
    int cheapestIndex = 0, cheapestCost = 2147483647;
    int cheapest2ndIndex = 0;
    bool secondCheap = false;
    for (int i = 0; i < menuNum; i++) {
        if (menuCost[i] < cheapestCost) {
            cheapest2ndIndex = cheapestIndex;
            cheapestIndex = i;
            cheapestCost = menuCost[i];
            secondCheap = true;
        } else if ((menuCost[i] == cheapestCost)) {
            if (secondCheap) {
                cheapest2ndIndex = i;
                secondCheap = false;
            }
            continue;
        }
    }

    cout << menuName[cheapest2ndIndex] << endl;
}