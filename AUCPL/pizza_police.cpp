#include <bits/stdc++.h>
#include <set>
using namespace std;

int sol1(void) { // Stupid TLE error
    int numQueue;
    vector<string> queue;
    set<string> uniqueNames; // Unqiue names
    map<string, int> personRounds; // How many times they went to get pizza

    // Input
    cin >> numQueue;
    for (int i = 0; i < numQueue; i++) {
        string name;
        cin >> name;

        queue.push_back(name);
        uniqueNames.insert(name);
        personRounds[name] = 0;
    }
    
    set<string> tempNames = uniqueNames; // temporary set of all names to modify

    for (int i = 0; i < numQueue; i++) { // go through list
        bool ruleBroken = false;
        if (tempNames.size() == 0) { // Every can go for another round of PIZZA!!!
            tempNames = uniqueNames; // Reset names
        }

        personRounds[queue[i]] += 1; // give pizza
        int nameRemoved = tempNames.erase(queue[i]); 
        
        // Check if got pizza before everyone else
        if (nameRemoved < 1) { // name NOT removved (i.e current person already got a pizza)
            if (tempNames.size() != 0) {
                //cout << "RULE BORKEN! NOT EVERYONE GOT THEIR PIZZA" << endl;
                ruleBroken = true;
            } // If there's still people waiting for the queue
        }

        // Check if re-enterd more than once (max 2 pizza p/person)
        if (personRounds[queue[i]] > 2) {
            //cout << "RULE BORKEN! ONLY 2 PIZZA PER PERSON" << endl;
            ruleBroken = true;
        }

        if (ruleBroken == true) { 
            cout << queue[i] << endl;
        }
    }


    return 0;
}
int main(void) {
    int numQueue;
    map<string, int> pizzaRounds;
    vector<string> queue;

    // Input
    cin >> numQueue;
    for (int i = 0; i < numQueue; i++) {
        string name;
        cin >> name;

        pizzaRounds[name] = 0; // init each person
        queue.push_back(name);
    }
    
    int numUniquePpl = pizzaRounds.size();
    int pizzaRollouts = 0;

    for (auto i : queue) {
        pizzaRounds[i] += 1; // give person pizza
        if (pizzaRounds[i] == 1) {
            pizzaRollouts += 1;
        }
        bool ruleBroken = false;

        // If more than 2 pizza
        if (pizzaRounds[i] > 1) { // ate before someone
            if (pizzaRollouts != numUniquePpl) {
                ruleBroken = true;
            }
        }
        if (pizzaRounds[i] > 2) {
            ruleBroken = true;
        }

        if (ruleBroken == true) {
            cout << i << endl;
        }

    }
    

    return 0;
}