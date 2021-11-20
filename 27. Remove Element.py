#!/usr/bin/env python3

class Solution:
	def removeElement(self, nums: List[int], val: int) -> int:
		return_index = 0
		for i in range(len(nums)):
			if nums[i] != val:
				nums[return_index] = nums[i]
				return_index += 1
		return return_index