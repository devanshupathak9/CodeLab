from typing import Dict, List


class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.countMap: Dict[int, int] = {}
        for num in nums2:
            self.countMap[num] = self.countMap.get(num, 0) + 1

    def add(self, index: int, val: int) -> None:
        self.countMap[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.countMap[self.nums2[index]] = self.countMap.get(self.nums2[index], 0) + 1

    def count(self, tot: int) -> int:
        count = 0
        for num in self.nums1:
            if tot - num > 0 and self.countMap.get(tot - num, 0) > 0:
                count += self.countMap[tot - num]
        return count


def main():
    nums1 = [1, 2, 3, 4, 5, 6]
    nums2 = [1, 2, 3, 4, 5, 6]
    findsumpairs = FindSumPairs(nums1, nums2)
    findsumpairs.add(3, 2)
    print(findsumpairs.count(7))


main()
