/**
  * Created by sswzfly on 17/3/26.
  */
class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        x = int(math.sqrt(area))
        while x:
            if area % x == 0:
                break
            x -= 1
        return [area/x, x]
