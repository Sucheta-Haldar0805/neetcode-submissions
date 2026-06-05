class Solution {
public:
    bool isSafe(vector<vector<string>>& ans,vector<string>& board,int row,int col){
        int n = board.size();
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        //vertical
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //diagonal-left
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //diagonal-right
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<string>& board,int row){
        int n = board.size();
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(ans,board,row,j)){
                board[row][j] = 'Q';
                solve(ans,board,row+1);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(ans,board,0);
        return ans;
    }
};
