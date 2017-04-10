class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int x = -1, y = 1;
        int N = matrix.size();
        if(N == 0) {
            return ans;
        }
        int M = matrix[0].size();
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            vector<int> tmp;
            int r = i, c = 0;
            while(check(r, c, N, M)) {
                tmp.push_back(matrix[r][c]);
                r += x;
                c += y;
            }
            if(cnt&1) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
            cnt ^= 1;
        }
        for(int i = 1; i < M; i++) {
            vector<int> tmp;
            int r = N-1, c = i;
            while(check(r, c, N, M)) {
                tmp.push_back(matrix[r][c]);
                r += x;
                c += y;
            }
            if(cnt&1) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
            cnt ^= 1;
        }
        return ans;
    }
private:
    bool check(int x, int y, int N, int M) {
        if(x < 0 || x >= N || y < 0 || y >= M) {
            return false;
        }
        return true;
    }
};
