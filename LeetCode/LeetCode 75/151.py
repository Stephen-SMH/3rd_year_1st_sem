
def reverseWords(s: str) -> str:
      return " ".join(s.split()[::-1])

print(reverseWords("  hello world  ")) # "world hello"