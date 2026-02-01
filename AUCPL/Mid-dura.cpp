#include <bits/stdc++.h>
using namespace std;

void op(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}
void dfs(vector<vector<int>>& adj, vector<bool>& seen, int cNode, vector<int>& ans) {
    seen[cNode] = true;
    for (int u : adj[cNode]) {
        if (!seen[u]) {
            dfs(adj, seen, u, ans);
        }
    }
    ans.push_back(cNode);
}
vector<int> topSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> topComplete;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(adj, seen, i, topComplete);
        }
    }
    reverse(topComplete.begin(), topComplete.end());
    return topComplete;
}
int main(void) {
    op();
    int n;
    cin >> n;
    unordered_map<string, int> stringID;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        string s;
        int c;
        cin >> s >> c;
        stringID[s] = i;
        cost[i] = c;
    }
    int numCons;
    cin >> numCons;
    vector<vector<int>> edges(n);
    for (int i = 0; i < numCons; i++) {
        string f, t;
        cin >> f >> t;
        edges[stringID[f]].push_back(stringID[t]);
    }
    // Topological sort
    vector<int> topo = topSort(edges);
    // Dp[node][state] = max
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        int now = topo[i];
        for (int next : edges[now]) {
            // First rest
            dp[next][0] = max(dp[next][0], dp[now][0]);           // already rested once
            dp[next][0] = max(dp[next][0], cost[next]);           // rest here first time

            // Second rest
            dp[next][1] = max(dp[next][1], dp[now][1]);           // already rested twice
            dp[next][1] = max(dp[next][1], dp[now][0] + cost[next]);

            // Third rest
            dp[next][2] = max(dp[next][2], dp[now][2]);           // already rested thrice
            dp[next][2] = max(dp[next][2], dp[now][1] + cost[next]);

        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << "on node " << topo[i] << endl;
    //     for (int j = 0; j < 3; j++) {
    //         cout << "dp" << j << " : " << dp[topo[i]][j] << endl;
    //     }
    // }
    int mildID = stringID["mildura"];
    cout << max({dp[mildID][0], dp[mildID][1], dp[mildID][2]}) << endl;;
    return 0;
}
