class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int sr = 0 ,sc = 0;
        int er = m-1 ,ec = n-1;
        
        while(sr <= er && sc <= ec){
            //right
            for(int j=sc; j<=ec;j++){
                ans.push_back(matrix[sr][j]);
            }

            //down
            for(int i=sr+1;i<=er;i++){
                ans.push_back(matrix[i][ec]);
            }

            //left
            for(int j=ec-1;j>=sc;j--){
                if(sr == er) break;
                ans.push_back(matrix[er][j]);
            }
            //up
            for(int i=er-1;i>=sr+1;i--){
                if(sc == ec) break;
                ans.push_back(matrix[i][sc]);
            }
            sr++;
            sc++;
            er--;
            ec--;
        }
        return ans;
    }
};
