//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //making adjacency map
        unordered_map <int,vector<pair<int,int>>> adj;  // wt also
        for (auto &vec:edges){ // {u,v,w} 
            int u=vec[0];
            int v=vec[1];
            int w=vec[2]; 
            
            adj[u].push_back({v,w}); // u is connected to v with wt w 
            adj[v].push_back({u,w}); // v is connected to u with wt w
            // agar ump ki jgh vector use krte to corresponding index pe store kra dete
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // minHeap
        vector<int> result(n+1,INT_MAX); // n given in fn
        vector<int> parent(n+1); // n+1 nodes hain 
        // starting me to sab khud ke hi parents hain 
        for (int i=1; i<=n; i++){
            parent[i]=i;
        }
        //our source is 1 
        result[1] = 0; // 1 ki 1 se duri 
        // ab result updated to pq mein push krenge
        pq.push({0,1}); // {d,node} dis ke base pe short krna h tbhi use phle rkha 
        
        while (!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for (auto &it : adj[node]){ // means is node se ab ham kaha kaha ja skte hn
                int adjNode=it.first;
                int dist=it.second;
                if (d+dist < result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                    parent[adjNode]=node;
                }
            }
        } 
        int destNode=n; 
        if (result[destNode]==INT_MAX) return {-1}; // destNode pr kbhi phuche hi nhi to infinity ka whi rh gya 
        
        vector<int> path; 
        while (parent[destNode]!=destNode){
            path.push_back(destNode); 
            destNode=parent[destNode];
        }
        //
        path.push_back(1) ; // source push krna hoga, src aate hi while break so couldn't push
        reverse(path.begin(), path.end());

        // Insert the shortest path weight at the beginning of the vector
        path.insert(path.begin(), result[n]);

        return path; 
    }
};





//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends