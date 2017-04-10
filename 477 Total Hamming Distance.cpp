class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int bit[32];
        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) {
                    bit[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 32; j++) {
                if(!(nums[i] & (1 << j))) {
                    ans += bit[j];
                }
            }
        }
        return ans;
    }
};
