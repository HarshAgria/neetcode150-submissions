class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //  1 2 3 4 5 6 7 8 9 10
        // 1
        // 2
        // 3
        // 4
        // 5
        // 6
        // 7
        // 8
        // 9
        // 10

        vector<unordered_set<char>> r(9);
        vector<unordered_set<char>> c(9);
        vector<unordered_set<char>> box(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
        char x=board[i][j];
        int boxno=(i/3)*3 + (j/3);
        if(x=='.') continue;

                if(r[i].count(x) || c[j].count(x) || box[boxno].count(x)) return 0;

                r[i].insert(x);
                c[j].insert(x);
                box[boxno].insert(x);
            }
        }
        return 1;
    }
};
