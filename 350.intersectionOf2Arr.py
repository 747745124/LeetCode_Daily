class Solution:
    def intersect(self, nums1, nums2):
        presenceOne = dict.fromkeys(set(nums1+nums2), 0)
        presenceTwo = dict.fromkeys(set(nums1+nums2), 0)

        for num in nums1:
            presenceOne[num] += 1
        for num in nums2:
            presenceTwo[num] += 1

        res = []

        for num in nums1:
            if presenceOne[num] > 0 and presenceTwo[num] > 0:
                res.append(num)
                presenceOne[num] -= 1
                presenceTwo[num] -= 1

        return res
