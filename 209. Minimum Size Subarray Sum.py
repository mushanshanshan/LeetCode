#!/usr/bin/env python3

class Solution:
	def minSubArrayLen(self, target: int, nums: List[int]) -> int:
		answer = float("inf")
		left = 0
		right = 0
		count_sum = 0
		while right < len(nums):
			count_sum += nums[right]
			while count_sum >= target:
				answer = min(right - left + 1, answer)
				if count_sum - nums[left] >= target:
					count_sum -= nums[left]
					left += 1
				else:
					break
			right += 1
		return answer if answer != float("inf") else 0