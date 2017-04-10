class Solution {
public:
    int integerBreak(int n) {
        f[0] = f[1] = 0;
        for(int i = 2; i <= n; i++) {
            f[i] = 0;
            for(int j = 1; j <= i / 2; j++) {
                f[i] = max(f[i], max(f[j], j) * max(f[i-j], i - j));
            }
        }
        return f[n];
    }
private:
    int f[59];
};
