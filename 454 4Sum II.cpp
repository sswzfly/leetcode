class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        vector<int> x;
        x.resize(N*N);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                x[i*N + j] = A[i] + B[j];
            }
        }
        unordered_map<int, int> sum_map;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                sum_map[C[i] + D[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < N*N; i++) {
            auto it = sum_map.find(-x[i]);
            if(it != sum_map.end()) {
                ans += it->second;
            }
        }
        return ans;
    }
};
