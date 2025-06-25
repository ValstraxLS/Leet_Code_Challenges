"""
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
"""


class Solution(object):
    def twoSum(self: object, nums: list[int], target: int) -> list[int]:
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]


if __name__ == "__main__":
    print("Example 1:\nInput: nums = [2,7,11,15], target = 9\nExpected Output: [0,1]\n", end="")
    s1 = Solution()
    print(f"Output: {Solution.twoSum(s1, [2, 7, 11, 15], 9)}")

    print("\nExample 2:\nInput: nums = [3, 2, 4], target = 6\nExpected Output: [1, 2]\n", end="")
    s2 = Solution()
    print(f"Output: {Solution.twoSum(s2, [3, 2, 4], 6)}")

    print("\nExample 3:\nInput: nums = [3, 3], target = 6\nExpected Output: [0, 1]\n", end="")
    s3 = Solution()
    print(f"Output: {Solution.twoSum(s3, [3, 3], 6)}")
