class Solution:
    def judgeSquareSum(self, c):
        if c < 2:
            return False
        sqC = int(c**0.5)
        for i in range(0, sqC + 1):
            if ((c - i**2)**0.5).is_integer():
                return True
        return False


if __name__ == '__main__':
    s = Solution()
    print(s.judgeSquareSum(2**30))
