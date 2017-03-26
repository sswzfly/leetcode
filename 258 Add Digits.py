/**
  * Created by sswzfly on 17/3/26.
  */
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        ans = 0
        while num:
            ans += num%10
            num /= 10
        if ans % 9 == 0:
            ans = 9
        else:
            ans %= 9
        return ans
