# Given a 32-bit signed integer, reverse digits of an integer.
# #
# # Example 1:
# #
# # Input: 123
# # Output: 321
# # Example 2:
# #
# # Input: -123
# # Output: -321
# # Example 3:
# #
# # Input: 120
# # Output: 21


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = -x
            t = -1
        else:
            t = 1
        num = 0
        i = len(str(x)) - 1
        while x != 0:
            num += (x % 10) * (10 ** i) * t
            i -= 1
            x = x // 10
        if x > (2 ** 31 - 1) or x < (-2 ** 31) or num > (2 ** 31 - 1) or num < (-2 ** 31) :
            return 0
        return num
