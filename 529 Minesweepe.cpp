class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int, int> > q;
        q.push(make_pair(click[0], click[1]));
        while(!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            int x = u.first;
            int y = u.second;
            if(board[x][y] == 'M') {
                board[x][y] = 'X';
                break;
            }
            else if(board[x][y] == 'B' || isdigit(board[x][y])) {
                continue;
            }
            else if(board[x][y] == 'E') {
                int mine_nums = getMineNums(x, y, board);
                if(mine_nums == 0) {
                    board[x][y] = 'B';
                    for(int i = 0; i < 8; i++) {
                        int r = x + adj[i][0];
                        int c = y + adj[i][1];
                        if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
                            q.push(make_pair(r, c));
                        }
                    }
                }
                else {
                    board[x][y] = mine_nums + '0';
                }
            }
        }
        return board;
    }
private:
    int getMineNums(int x, int y, const vector<vector<char>>& board) {
        int ret = 0;
        int N = board.size();
        int M = board[0].size();
        for(int i = 0; i < 8; i++) {
            int r = x + adj[i][0];
            int c = y + adj[i][1];
            if(r < 0 || r >= N || c < 0 || c >= M) {
                continue;
            }
            if(board[r][c] == 'M') {
                ret++;
            }
        }
        return ret;
    }
    
    int adj[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
};
