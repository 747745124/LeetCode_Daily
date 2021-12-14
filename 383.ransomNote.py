from collections import Counter


class Solution:
    def canConstruct(self, ransomNote, magazine):
        ransomNote = list(ransomNote)
        magazine = list(magazine)
        c = list((Counter(ransomNote) & Counter(magazine)).elements())
        if len(c) >= len(ransomNote):
            return True
        return False


s = Solution()
s.canConstruct("fffbfg", "effjfggbffjdgbjjhhdegh")
