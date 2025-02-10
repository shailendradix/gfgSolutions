//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private: 
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,vector<int>& result){
        visited[node]=true;
        result.push_back(node); 
        
        for (int pdosi:adj[node]){
            if (!visited[pdosi]){
                dfs(pdosi,adj,visited,result); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<bool> visited(v,false); // v: no of vertices 
        vector<int> result; 
        
        dfs(0,adj,visited,result); // u:0  (starting node) 
        
        return result; 
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends