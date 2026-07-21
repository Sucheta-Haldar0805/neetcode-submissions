class Solution {
public:
    bool helper(vector<vector<int>>& graph,vector<bool>& vis,vector<bool>& recPath,int src){
        int n = graph.size();
        vis[src] = true;
        recPath[src] = true;

        for(int i=0;i<n;i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src){
                if(!vis[v]){
                    if(helper(graph,vis,recPath,v)){
                        return true;
                    }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(prerequisites,vis,recPath,i)){
                    return false;
                }
            }
        }
        return true;
    }
};
