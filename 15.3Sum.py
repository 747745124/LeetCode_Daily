class Solution:
    def threeSum(self, nums):
        nums = sorted(nums)
        hashSet = {}
        res = []
        for i in range(len(nums)):

            presences = {}
            for j in range(i+1, len(nums)):

                if -nums[i]-nums[j] in presences:
                    tmp = (nums[i], nums[j], -nums[i] - nums[j])
                    if(tmp in hashSet):
                        continue
                    hashSet[tmp] = 1
                    res.append(list(tmp))

                presences[nums[j]] = j

        return res


if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    Sol = Solution()
    print(Sol.threeSum(nums))
