class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[0:m+n] = sorted(nums1[:m]+nums2)
        # print(nums1)


if __name__ == '__main__':
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    m = 3
    n = 3
    Solution().merge(nums1, m, nums2, n)
    print(nums1)
