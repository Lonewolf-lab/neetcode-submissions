class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                string row = string(1, board[i][j]) + " ROW " + to_string(i);
                string col = string(1, board[i][j]) + " COL " + to_string(j);
                string sub_box = string(1, board[i][j]) + " SUB-BOX " + to_string(i/3) + " " + to_string(j/3);

                if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(sub_box) != s.end()) return false;

                s.insert(row);
                s.insert(col);
                s.insert(sub_box);
            }
        }
        return true;

    }
};