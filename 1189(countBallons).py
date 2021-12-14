class Solution:
    def maxNumberOfBalloons(self, text):
        words = dict.fromkeys([chr(i) for i in range(97, 123)], 0)
        for word in text:
            words[word] += 1

        count = 0
        if(words['b'] >= 1 and words['a'] >= 1 and words['l'] >= 2 and words['o'] >= 2 and words['n'] >= 1):
            words['b'] -= 1
            words['a'] -= 1
            words['l'] -= 2
            words['o'] -= 2
            words['n'] -= 1
            count += 1
        else:
            return count

        return count
        # balloon, 1a,1b,2l,2o,1n


if __name__ == '__main__':
    s = Solution()
    print(s.maxNumberOfBalloons("krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmvnlhvuahhqfqkpqgmtcildcffqfprxgbxmvqpbfteyqauhirpgxmhdtgucjvzmpxahhsjsqbvikynzigxavfkjprbmwwqeilzwmfwesrdvbrekzdshhtcvffcvenugqoilfzwvqkzmduajvkexemxwttgiscsirwqcqtuwztmgkcspzjogxpnvrwcgtsgixfbyzdruzjxeqqxoqpqqxmoczvxmcvllasyzlnbffcvvkeqqtqxodgzrwxuarhtrxfhiczvxggpjrjafvfytnchvpqyfocdguerhvqycezrwxuarhtrxfhiczvxggpjrjafvfytnch"))
