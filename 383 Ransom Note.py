class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        list_note = list(ransomNote)
        list_magazine = list(magazine)
        for i in list_note:
            if i not in list_magazine:
                return False
            else:
                list_magazine.remove(i)
        return True
        
