# You are given an integer array values where values[i] represents the value of the ith sightseeing spot.
# Two sightseeing spots i and j have a distance j - i between them.
# The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j:
# the sum of the values of the sightseeing spots, minus the distance between them.
# Return the maximum score of a pair of sightseeing spots.

from typing import List

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        max_value = 0
        array = []
        for i in range(len(values)):
            pair_sum = values[i] + i
            if pair_sum > max_value:
                max_value = pair_sum
                array.append(max_value)
            else:
                array.append(max_value)

        max_score = 0
        for i in range(len(values) - 1, 0, -1):
            pair_sum = values[i] - i
            if pair_sum + array[i - 1] > max_score:
                max_score = pair_sum + array[i - 1]
        return max_score

if __name__ == "__main__":
    object = Solution()

    print(object.maxScoreSightseeingPair([8, 1, 5, 2, 6]))
    print(object.maxScoreSightseeingPair([1, 2]))
    print(object.maxScoreSightseeingPair([8, 1, 5, 2, 13, 6, 3, 7, 12]))
