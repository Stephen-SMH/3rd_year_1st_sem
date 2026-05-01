from typing import List

def productExceptSelf( nums: List[int]) -> List[int]:
      length = len(nums)
      
      prefix = [1] * length
      suffix = [1] * length

      for i in range(1, length):
            prefix[i] = prefix[i - 1] * nums[i - 1]

            
      print(prefix)

      for i in range(length - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1]
      
      print(suffix)

      answer = [prefix[i] * suffix[i] for i in range(length)]
      return answer
      
print(productExceptSelf([1, 2, 3, 4])) # [24, 12, 8, 6]