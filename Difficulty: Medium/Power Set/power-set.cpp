class Solution {
    private:
        void solve (int curr, string s, string &st, vector<string> &res){
            if (curr==s.size()){
                res.push_back(st); 
                return;
            }
            
            st.push_back(s[curr]);
            
            solve(curr+1,s,st,res);
            
            st.pop_back();
            
            solve(curr+1,s,st,res);
        }
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> res;
        int curr=0; 
        string st = "";
        solve(curr,s,st,res);
        sort(res.begin(),res.end());
        return res;
        
    }
};