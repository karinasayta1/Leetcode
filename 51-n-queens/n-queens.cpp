class Solution {
bool isSafe(vector<string> & board, int row, int col, int n){
    //horizontal 
    for(int j = 0; j<n; j++){
        if(board[row][j]=='Q')
          return false;
    }

    //vertical
    for(int i = 0; i<n; i++){
        if(board[i][col]=='Q')
          return false;
    }

    //diagonally left
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q')
          return false;
    }

    //right diagoanl 
    for(int i=row, j=col; i>=0 && j>=0; i--,j++){
        if(board[i][j]=='Q')
          return false;
    }

    return true;
}
void Nqueens( vector<string> & board, int row, int n, vector<vector<string>> & result){
    if(row==n){
        result.push_back(board);
        return;
    }

    for(int i = 0; i<n ; i++){
        if(isSafe(board, row, i, n)){
            board[row][i]='Q';
            Nqueens(board, row+1, n, result);
            board[row][i]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> result;

        Nqueens(board, 0, n, result);
        return result;
    }
};