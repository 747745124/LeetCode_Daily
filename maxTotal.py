class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        rewardValues = tuple(dict.fromkeys(rewardValues))

        return self.maxRewardWithIndex(rewardValues, 0, 0)
        
    def maxRewardWithIndex(self, rewardValues: tuple[int], index: int, totalReward: int) -> int:
        if index >= len(rewardValues):
            return totalReward
        if totalReward > rewardValues[-1]:
            return totalReward

        maxReward = 0

        if rewardValues[index] > totalReward:
            # case 1: include rewardValues[index]
            maxReward = max(maxReward, self.maxRewardWithIndex(rewardValues, index, totalReward + rewardValues[index]))

        # case 2: exclude rewardValues[index]
        maxReward = max(maxReward, self.maxRewardWithIndex(rewardValues, index + 1, totalReward))
        return maxReward
        
        