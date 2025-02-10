//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {// pahle mere bachcho ko stack mien dalo 
  private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[u]=true;
        
        for (int& v:adj[u]){ // adj[u] represents vector of element connected with u
            if (!visited[v]){
                dfs(v,adj,visited,st);
            }
            
        }
        st.push(u); // andar ke v wale bhi isi ki wjh se pahle stack mein chle jaayenge and recurrsion last mein lautkar u ke pass aayega tab u jaayega, yehi u 'v' ka kam bhi niptayega 
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int v= adj.size(); // no of vertices
        vector<bool> visited(v,false);
        stack<int> st;
        for (int i=0; i<v; i++){
            if (!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> res;
        while (!st.empty()){
            int num=st.top();
            res.push_back(num);
            st.pop();
        }
        
        return res; 
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends