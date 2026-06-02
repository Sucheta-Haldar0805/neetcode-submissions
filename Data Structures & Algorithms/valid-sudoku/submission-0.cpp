class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char digit){
        //vertical
        for(int i=0;i<=8;i++){
            if(i != row && board[i][col] == digit){
                return false;
            }
        }
        //horizontal
        for(int j=0;j<=8;j++){
            if(j != col && board[row][j] == digit){
                return false;
            }
        }
        //3*3 grid
        int stRow = (row/3)*3;
        int stCol = (col/3)*3;

        for(int i=stRow;i<=stRow+2;i++){
            for(int j=stCol;j<=stCol+2;j++){
                if((i != row || j != col) && board[i][j] == digit){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] != '.'){
                    if(!isSafe(board, row, col, board[row][col])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};