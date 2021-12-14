class Solution:
    def maxSubArray(self, nums):
        # Kadane's Algorithm
        maxCurrent = maxGlobal = nums[0]
        for i in range(1, len(nums)):
            # the maxCurrent is sum(maxCurrent+num)(the max subarray before this elem) or num
            maxCurrent = max(nums[i], maxCurrent + nums[i])
            # update maxGlobal
            maxGlobal = max(maxCurrent, maxGlobal)
        return maxGlobal
