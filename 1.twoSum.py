class Solution:
    def twoSum(self, nums, target):
        # memoization
        hashset = {}

        for idx, num in enumerate(nums):
            if target - num in hashset:
                return [hashset[target-num], idx]
            hashset[num] = idx

        return [-1, -1]
