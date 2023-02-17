class Solution {
public:
    bool isvalid(vector<vector<char>>&board, int row, int col, char num){
        for(int i=0; i<9;i++){
            if(board[i][col]==num)
                return false;
        }
        for(int i=0; i<9;i++){
            if(board[row][i]==num)
                return false;
        }
        int r=(row/3)*3;
        int c=(col/3)*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[r+i][j+c]==num)
                    return false;
            }
        }
        return true;
    }
    bool answer(vector<vector<char>>&board, int i, int j){
        if(j==9){
            i=i+1;
           j=0;
        }
        if(i==9)
            return true;
        if(board[i][j]=='.'){
            for(char c='1'; c<='9'; c++){
                if(isvalid(board, i,j,c)){
                    board[i][j]=c;
                    if(answer(board,i,j+1)==true){
                        return true;
                    }
                    board[i][j]='.';
                }
            }
        }
        else{
            if(answer(board,i,j+1))
                return true;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ass=answer(board,0,0);
    }
};