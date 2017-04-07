class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> M;
        for(int i = 0; i < nums.size(); i++) {
            M[nums[i]]++;
        }
        vector<pair<int, int> > vec;
        for(auto it = M.begin(); it != M.end(); it++) {
            vec.push_back(make_pair(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
private:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
