class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(numbers) - 1
        while l < r:
            if numbers[l] + numbers[r] == target:
                break
            elif numbers[l] + numbers[r] > target:
                r -= 1
            else:
                l += 1
        return [l+1, r+1]
