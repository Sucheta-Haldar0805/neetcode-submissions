class Solution {
public:
    void dfs(vector<vector<int>>& adj,int n,int src,vector<bool>& vis){
        vis[src] = true;

        for(auto v : adj[src]){
            if(!vis[v]){
                dfs(adj,n,v,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,n,i,vis);
            }
        }
        return cnt;
    }
};
