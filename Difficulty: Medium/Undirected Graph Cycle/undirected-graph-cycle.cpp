//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution { 
  private:
    bool isCycleBFS(vector<vector<int>>& adj,int u, vector<bool>& visited){
        queue<pair<int,int>> q;
        
        q.push({u,-1});
        visited[u]=true;
        
        while (!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            
            int source=p.first;
            int parent=p.second;
            
            for (int &v:adj[source]){
                if (!visited[v]){
                    visited[v]=true;
                    q.push({v,source}); // v ko source ne call kiya to wo uskaparent ho gya
                }
                else if(v!=parent){// if mein not visited check kiya to else mein aayega hi tabhiagar visited hoga, so overall ye condition hui visited and not parent 
                    // means visited and not parent 
                    return true;
                }
            }
        }
        return false; 
    }
  public:// dfs se to intuitive bhi lg rha tha, :) 
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<bool> visited(v,false);
        
        
        
        for (int i=0; i<v; i++){
            if (!visited[i] && isCycleBFS(adj,i,visited)){
                return true;
            }
        }
        return false; 
    }
  
};
/*
class Solution { 

  private: // using dfs 
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent){
        visited[u]=true;
        
        for (int &v: adj[u]){
            if (v==parent) continue; // vapas parent ko kyu hi visit krenge 
            
            if(visited[v]) return true;
            
            if (isCycleDFS(adj,v,visited,u)) return true;
        }
        return false; 
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        // disconnected graph bhi ho skta hai re baba 
        // iske liye dfs call krte time loop lagana hoga 
        int v=adj.size();
        
        vector<bool> visited(v,false);
        
        for (int i=0; i<v; i++){ //i is starting node, each node will be starting node(u), due to possibility of disconncted graphs
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
                return true; 
            }
        }
        return false; // kahin cycle n mili 
        
    }

};
*/
// dfs se visit krte jao and visited ko unordered_map mien dalte jaao 
// jisko bhi visit kro usko check krte jao pahle se hi to nhi present hai ump mein 
// agar pahle se present hai and wo parent nhi h (undirected h na) means cycle hai nhi to nhi hai :) 
// directed graph ke case mien parent ka bawal hi nahi agar present hi h then cycle

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends