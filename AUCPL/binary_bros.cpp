#include <bits/stdc++.h>
using namespace std;

long long binarySearch(vector<long long> arrayParam, long long numFind){
    long long arraySize = arrayParam.size();
    long long leftPointer = 0, rightPointer = arraySize - 1;
    long long middlePointer = leftPointer + (rightPointer - leftPointer) / 2;

    while (leftPointer <= rightPointer) {
        if (arrayParam[middlePointer] == numFind) {
            return middlePointer + 1;

        } else if (numFind > arrayParam[middlePointer]) {
            leftPointer = middlePointer + 1;

        } else if (numFind < arrayParam[middlePointer]) {
            rightPointer = middlePointer - 1;
        }

        middlePointer = leftPointer + (rightPointer - leftPointer) / 2;
    }

    return -1;

}

int main(void) {
    long long winningNums, ticketsBought;
    vector<long long> winning, bought, winningBought;

    cin >> winningNums;
    for (long long i = 0; i < winningNums; i++) {
        long long x;
        cin >> x;
        winning.push_back(x);
    }

    cin >> ticketsBought;
    for (long long i = 0; i < ticketsBought; i++) {
        long long x;
        cin >> x;
        bought.push_back(x);
    }

    sort(bought.begin(), bought.end());

    long long sumTickets = 0;
    long long lastNumber = -1, lastIndex = -1; // initialize last number and index used to reduce binary search

    for (long long i = 0; i < ticketsBought; i++) {
        if (bought[i] == lastNumber) { // Check if dupe ticket already registered
            if (lastIndex > 0) { // if last ticket is in winning tickets
                sumTickets += lastIndex;
            }
            continue;

        } else { 
            lastIndex = binarySearch(winning, bought[i]);
            lastNumber = bought[i];

            if (lastIndex > 0) { // If bought ticket is winning number
                sumTickets += lastIndex;
            }
        }
    }

    cout << sumTickets << endl;
    return 0;
}