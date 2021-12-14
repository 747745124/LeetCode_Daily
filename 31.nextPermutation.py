def nextPermutations(nums):
    i = len(nums) - 2
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1

    if i == -1:
        return nums.reverse()

    j = len(nums) - 1
    while nums[j] <= nums[i]:
        j -= 1

    nums[i], nums[j] = nums[j], nums[i]
    nums[i + 1:] = nums[len(nums) - 1:i:-1]
    return


if __name__ == "__main__":
    nums = [3, 2, 1]
    nextPermutations(nums)
    print(nums)
