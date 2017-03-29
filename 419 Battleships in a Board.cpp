class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0; i < board.size(); i++) {
            int j = 0;
            for(; j < board[i].size(); j++) if(board[i][j] == 'X') {
                if(i == 0 || board[i-1][j] == '.') {
                    ans++;
                    j++;
                    while(j < board[i].size() && board[i][j] == 'X') {
                        j++;
                    }
                }
            }
            
        }
        return ans;
    }
};
