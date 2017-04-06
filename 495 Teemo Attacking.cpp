class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int t_end = 0;
        for(int i = 0; i < timeSeries.size(); i++) {
            if(t_end >= timeSeries[i]) {
                ans += duration - (t_end - timeSeries[i]);
            }
            else {
                ans += duration;
            }
            t_end = timeSeries[i] + duration;
        }
        return ans;
    }
};
