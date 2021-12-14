class Solution:
    def breakPalindrome(self, palindrome):
        if len(palindrome) == 1:
            return ""

        for i in range(len(palindrome)):
            if (palindrome[i] != "a"):
                for elem in (palindrome[:i]+"a"+palindrome[i+1:]):
                    if elem != "a":
                        return palindrome[:i]+"a"+palindrome[i+1:]
                return palindrome[:-1]+"b"

        return palindrome[:-1]+"b"
