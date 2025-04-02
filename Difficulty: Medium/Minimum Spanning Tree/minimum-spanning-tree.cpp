//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
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

    int kruskal(vector<vector<int>>& vec) { 
        int sum = 0; 
        for (auto& temp : vec) {
            int u = temp[0];
            int v = temp[1]; 
            int wt = temp[2]; 
            
            // ab parent nikal ke check kr lenge ki dono same compo me h ki nhi
            int parent_u = find(u); // find function from DSU 
            int parent_v = find(v); 
            
            if (parent_u != parent_v) {
                unionSet(u, v); 
                // since union kiya means us edge ko le liya
                sum += wt;
            }
        }
        return sum; 
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> vec;
        parent.resize(V);
        rank.resize(V, 0); // parent and rank use in find and unionset in DSU must be initialized 

        for (int i = 0; i < V; i++){
            parent[i] = i; // DSU me starting me khud khud ka parent sbhi
        }

        for (int u = 0; u < V; u++){
            for (auto& temp : adj[u]){
                int v = temp[0]; 
                int wt = temp[1]; 
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2]; 
        }; 
        sort(vec.begin(), vec.end(), comparator);//acc ot wt sort krna h na
    
        return kruskal(vec); 
    }
};

/*
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        typedef pair<int,int> p; 
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int sum=0;
        int wt=0;
        int node=0;
        vector<int> visited(V,0); // inMST (matlab mst me dal liya h ya nhi)
        //visited[node]= 1; // yaha agar phle hi visit kr loge and neeche visted[node] pe continue kr jaaoge to kabhi while loop me ghusoge hi nhi
        //sum+=wt; // visit krne ke bad hi sum update krenge
        minHeap.push({wt,node});
        
        
        while (!minHeap.empty()){
            
            auto p=minHeap.top();
            minHeap.pop(); 
            int wt=p.first;
            int node=p.second;
            
            if (visited[node] == 1) continue; // bhai neeche to tum revisite kr rhe ho yrr
            visited[node]=1;
            sum+=wt;
            
            // ab is node se kaha kaha jaa skte hain .....
            for (auto &newPair:adj[node]){
                int wt=newPair[1];
                int newNode=newPair[0]; // bhai newPair vector hai yaha
                if (visited[newNode]!=1){
                    //visited[newNode]=1;
                   // sum+=wt;
                    minHeap.push({wt,newNode}); // parent chahiye hota to "node" bhi dal dete yhan comma krke , ki kis node se aya hu
                }
                else {
                    continue; //yaha
                }
            }
        }
        
        return sum; 
        
    }
};
*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends