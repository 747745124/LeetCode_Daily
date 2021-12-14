import string
from collections import OrderedDict


class Solution():
    def reverseOnlyLetters(self, s):
        lower = string.ascii_lowercase
        upper = string.ascii_uppercase
        words = list(lower)+list(upper)
        s = list(s)
        j = len(s)-1
        for i in range(len(s)):
            if(i == j):
                break
            word = s[i]
            if word not in words:
                i += 1
                continue

            while(s[j] not in words):
                j -= 1

            new_word = s[j]

            if word in words and new_word in words:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1

        return ''.join(map(str, s))

    def reverseOnlyLetters2(self, s):
        pos = OrderedDict()

        for i in range(len(s)):
            if not s[i].lower().isalpha():
                pos[i] = s[i]

        s = (''.join(filter(lambda char: char.lower().isalpha(), s)))[::-1]

        for p in pos:
            s = s[:p] + pos[p] + s[p:]

        return s
        # return pos


if __name__ == '__main__':
    sol = Solution()
    print(sol.reverseOnlyLetters2("Test1ng-Leet=code-Q!"))
