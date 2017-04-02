class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        for(int i = 0; i + 1 < A.size(); i++) {
            A[i] = A[i+1] - A[i];
        }
        if(A.size() <= 1) {
            return 0;
        }
        A.erase(A.end() - 1);
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            int cnt = 1;
            int j = i+1;
            while(j < A.size()) {
                if(A[i] == A[j]) {
                    cnt++;
                }
                else {
                    break;
                }
                j++;
            }
            i = j-1;
            ans += cnt*(cnt-1) / 2;
        }
        return ans;
    }
};
