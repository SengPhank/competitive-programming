#include <bits/stdc++.h>
using namespace std;

// bfs
int main(void) {
    int numNodes;
    cin >> numNodes;
    unordered_map<int, int> nColors; // { node : color }

    int temp;
    for (int i = 0; i < numNodes; i++) {
        cin >> temp;
        nColors[i] = temp;
    }

    // check if each node has only 1 color
    unordered_map<int, int> nParent; // {nodeParent, color}
    for (int i = 1; i < numNodes; i++) {
        cin >> temp;
        if (nParent[temp] == 0) {
            nParent[temp] = nColors[i];
        } else if (nParent[temp] != nColors[i]) {
            cout << "Invalid" << endl;
            return 0;
        }
    }

    cout << "Valid" << endl;
    return 0;
}
