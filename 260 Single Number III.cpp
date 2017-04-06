class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tot_xor = 0;
        for(int i = 0; i < nums.size(); i++) {
            tot_xor ^= nums[i];
        }
        int bit;
        for(int i = 0; i < 32; i++) {
            if(tot_xor & (1 << i)) {
                bit = i;
                break;
            }  
        }
        
        int x = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & (1 << bit)) {
                x ^= nums[i];
            }
        }
        vector<int> ans = {x};
        ans.push_back(tot_xor ^ x);
        return ans;
    }
};
