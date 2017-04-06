class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        memset(vis, -1, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < M.size(); i++) {
            if(vis[i] == -1) {
                dfs(i, i, M.size(), M);
                ans++;
            }
        }
        return ans;
    }
private:
    void dfs(int u, const int& color, const int& N, const vector<vector<int>>& M) {
        vis[u] = color;
        for(int i = 0; i < N; i++) {
            if(vis[i] == -1 && (M[u][i] || M[i][u])) {
                dfs(i, color, N, M);
            }
        }
    }
    
    int vis[201];
};
