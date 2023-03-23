#!/usr/bin/env python3

class Solution:
	def sortedSquares(self, nums: List[int]) -> List[int]:
		left = 0
		right = len(nums) - 1
		index = right
		answer = [-1] * len(nums)
		while left < right:
			if nums[left] + nums[right] < 0:
				answer[index] = nums[left] ** 2
				left += 1
			elif nums[left] + nums[right] > 0:
				answer[index] = nums[right] ** 2
				right -= 1
			else:
				answer[index] = nums[right] ** 2
				index -= 1
				answer[index] = nums[right] ** 2
				left += 1
				right -= 1
			index -= 1
		answer[0] = nums[right] ** 2
		return answer