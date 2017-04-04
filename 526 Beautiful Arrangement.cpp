class Solution {
public:
    int countArrangement(int N) {
        memset(digit_used, 0, sizeof(digit_used));
        return dfs(0, N);
    }
private:
    int dfs(int dep, int N) {
        if(dep == N) {
            return 1;
        }
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            if(!digit_used[i] && (i % (dep + 1) == 0 || (dep + 1) % i == 0)) {
                digit_used[i] = 1;
                ans += dfs(dep+1, N);
                digit_used[i] = 0;
            }
        }
        return ans;
    }
    
    int digit_used[16];
};
