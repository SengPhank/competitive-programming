#include <bits/stdc++.h>
#include <queue>
using namespace std;

short PKey(deque<int> *dq) {
    // Requirements
    if (dq->size() < 2) {
        cout << "INVALID" << endl;
        return 1;
    }

    int num1 = dq->back();
    dq->pop_back();
    int num2 = dq->back();
    dq->pop_back();

    dq->push_back(num1+num2);
    return 0;
}
short BKey(deque<int> *dq) {
    // Requirements
    if (dq->empty()) {
        cout << "INVALID" << endl;
        return 1;
    }

    dq->pop_back();
    return 0;
}

deque<int> CKey() {
    deque<int> newdq;
    return newdq;
}

short TKey(deque<int> *dq) {
    // Requirements
    if (dq->empty()) {
        cout << "INVALID" << endl;
        return 1;
    }

    int num = (dq->back()/3);
    dq->pop_back();
    dq->push_back(num);
    return 0;
}

short DKey(deque<int> *dq) {
    // Requirements
    if (dq->empty()) {
        cout << "INVALID" << endl;
        return 1;
    }

    int num = (dq->back() * 2);
    dq->pop_back();
    dq->push_back(num);
    return 0;
}

int main(void) {
    int numInp;
    cin >> numInp;

    deque<int> dq;
    char inputValue;
    for (int i = 0; i < numInp; i++) {
        cin >> inputValue;
        if (inputValue >= 48 && inputValue <= 57) { // Number 0-9
            dq.push_back(inputValue - '0');
        } else if (inputValue == '+') { // Add last 2 digit
            if (PKey(&dq) == 1) return 0; 
        } else if (inputValue == 'B') { // Remove latest element
            if (BKey(&dq) == 1) return 0;
        } else if (inputValue == 'C') { // Clear all queue
            dq = CKey(); 
        } else if (inputValue == 'T') { // Replace with 1/3 of top
            if (TKey(&dq) == 1) return 0;
        } else if (inputValue == 'D') { // Replace with double of top
            if (DKey(&dq) == 1) return 0;
        } else {
            cout << "INVALID" << endl;
            return 1;
        }
    }

    // Check for final calculations size
    if (dq.size() != 1) {
        cout << "INVALID" << endl;
        return 0;
    } else {
        cout << dq.back() << endl;
    }

    return 0;

}