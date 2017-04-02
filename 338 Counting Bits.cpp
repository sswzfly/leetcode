class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i = 0; i <= num; i++) {
            ans.push_back(count_num(i));
        }
        return ans;
    }
private:
    int count_num(int n) {
        int ans = 0;
        while(n) {
            n &= (n-1);
            ans++;
        }
        return ans;
    }
};
