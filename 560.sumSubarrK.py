class Solution:
    # input size : from 1 to 20000
    # upper time complexity : O(nlogn)
    def subarraySumBF(self, nums, k):
        sumList = [0]
        sum = 0
        for num in nums:
            sum += num
            sumList.append(sum)

        cnt = 0
        for i in range(0, len(nums)+1):
            for j in range(0, len(nums)+1):
                if (i > j) and sumList[i]-sumList[j] == k:
                    cnt += 1

        return cnt

    def subarraySum(self, nums, k):
        sumOccur = dict({0: 1})
        sum = 0
        cnt = 0
        for i in range(0, len(nums)):
            sum += nums[i]
            if sum not in sumOccur:
                sumOccur[sum] = 0
            if (sum-k) in sumOccur:
                cnt += sumOccur[sum-k]
            sumOccur[sum] += 1

        return cnt
