class Solution {
public:
    struct element {
        int val;
        int idx;
        bool operator < (const element& rhs) const {
            return val > rhs.val;
        }
    };
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<element> vec;
        vec.resize(2 * nums.size());
        for(int i = 0; i < nums.size(); i++) {
            vec[i] = element{nums[i], i};
            vec[i+nums.size()] = element{nums[i], i+nums.size()};
        }
        vector<int> ans;
        ans.resize(nums.size());
        priority_queue<element> q;
        for(int i = 0; i < vec.size(); i++) {
            while(!q.empty()) {
                if(q.top().val < vec[i].val) {
                    ans[q.top().idx] = vec[i].val;
                    q.pop();
                }
                else {
                    break;
                }
            }
            if(i < nums.size()) {
                q.push(element{nums[i], i});
            }
        }
        while(!q.empty()) {
            ans[q.top().idx] = -1;
            q.pop();
        }
        return ans;
    }
};
