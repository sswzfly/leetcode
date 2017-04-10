class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        int k = 9;
        int fk = 1;
        bool first = true;
        for(int i = 0; i < n; i++) {
            fk *= k;
            if(k > 0)  {
                if(first == true) first = false;
                else k--;
            }
            ans += fk;
        }
        return ans;
    }
};
