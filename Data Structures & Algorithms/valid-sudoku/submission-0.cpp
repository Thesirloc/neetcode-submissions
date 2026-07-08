class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rowsets(board.size());
        vector<set<int>> colsets(board.size());
        vector<set<int>> gridsets(board.size());
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                if(rowsets[i].find(board[i][j]) != rowsets[i].end()) return false;
                else rowsets[i].insert(board[i][j]);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[j][i] == '.') continue;
                if(colsets[i].find(board[j][i]) != colsets[i].end()) return false;
                else colsets[i].insert(board[j][i]);
            }
        }
        int gridindex=0;
        for(int i=0;i<board.size();i=i+3){
            for(int j=0;j<board[0].size();j=j+3){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(board[i+k][j+l] == '.') continue;
                        if(gridsets[gridindex].find(board[i+k][j+l]) != gridsets[gridindex].end()) return false;
                        else gridsets[gridindex].insert(board[i+k][j+l]);
                    }
                }
                gridindex++;
            }
        }
        return true;
    }
};
