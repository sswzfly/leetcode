class Solution {
    public:
        string toHex(int num) {
            char ans[256];
            sprintf(ans, "%x", num);
            return ans;
        }
};
