class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tot = sum(nums)
        min_x = min(nums)
        n = len(nums)
        return tot - min_x * n
