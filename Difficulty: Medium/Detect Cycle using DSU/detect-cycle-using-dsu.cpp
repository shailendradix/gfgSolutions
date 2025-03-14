//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unionSet(int x, int y) { // Renamed from union to unionSet
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

public:
    // Function to detect cycle using DSU in an undirected graph.
    bool detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);

        // Initialize DSU
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Process all edges
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                if (u < v) { // Avoid double checking same edge
                    int parent_u = find(u);
                    int parent_v = find(v);

                    if (parent_u == parent_v) return true; // Cycle detected

                    unionSet(u, v); // Merge components
                }
            }
        }

        return false; // No cycle found
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends