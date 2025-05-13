#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> bfs;
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
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
        adj[v].push_back(u); // comment this line if the graph is directed
    }

    Solution obj;
    vector<int> res = obj.bfsOfGraph(V, adj);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
