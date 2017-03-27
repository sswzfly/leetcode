class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        ans = 0
        idx = 0
        for i in g:
            while idx < len(s):
                if s[idx] >= i:
                    ans += 1
                    idx += 1
                    break
                else:
                    idx += 1
        return ans
                
