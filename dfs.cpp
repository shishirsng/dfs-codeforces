#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &res) {
        vis[node] = 1;
        res.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, res);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> res;

        dfs(0, adj, vis, res);
        return res;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this for directed graph
    }

    Solution obj;
    vector<int> res = obj.dfsOfGraph(V, adj);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
