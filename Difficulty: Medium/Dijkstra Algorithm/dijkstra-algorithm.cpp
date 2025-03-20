//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code 
        //priority_queue<int,vector<int>,greater<int>> pq; // minHeap: ab int ko pair<int,int> se rpelace kr do 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int v=adj.size(); /// no of vertices 
        vector<int> result(v, INT_MAX);
        result[src] = 0; // khud tk phuchne mein to 0 rupee hi lgenge
        
        pq.push({0, src}); // kharcha, node (source se is node tk phuchne mein kharcha)
        
        // ab source ke connected all nodes ko explore krenge and jo good choice hogi use result array and priority queue mien enter krayenge nhi to reject krke aage bdhte chale jaayenge
        while (!pq.empty()) {
            int d = pq.top().first; // distance neares possible from source to this node
            int node = pq.top().second; // neighbour...neighbhours
            pq.pop();
            
            // ab explore krenge is node se kaha kaha ja skta hu, koi good choice dikhi to use pq mein dal lenge further usse kaha kaha j skte explore krenge
            for (auto &vec : adj[node]) {
                int adjNode = vec.first; // neighbour node
                int wt = vec.second;  // dist of neighbour node
                
                if (d + wt < result[adjNode]) { // then good choice
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        return result; 
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends