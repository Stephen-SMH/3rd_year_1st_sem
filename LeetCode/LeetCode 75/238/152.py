from typing import List


def maxProduct(nums: List[int]) -> int:
        
      length = len(nums)
      prefix = [1] * length
      suffix = [1] * length

      for i in range(1, length):
            prefix[i] = prefix[i - 1] * nums[i - 1] * nums[i]

      for i in range(length - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1] * nums[i]

      print(prefix)
      print(suffix)

      return max(prefix)

print(maxProduct([2, 3, -2, 4])) # 6



      