#include <bits/stdc++.h>
#include <queue>
using namespace std;


int main(void) {
    int numStack, bookSize;
    cin >> numStack;

    deque<int> stackBook;
    for (int i = 0; i < numStack; i++) {
        cin >> bookSize;

        // Continue on first book
        if (stackBook.empty()) {
            stackBook.push_front(bookSize);
            continue;
        }

        // Pop books smaller than front current
        while (bookSize > stackBook.front() && !stackBook.empty()) {
            stackBook.pop_front();
        }
        stackBook.push_front(bookSize);

    }

    cout << stackBook.size() << endl;

    return 0;
}