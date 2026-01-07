class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matching_open = {')':'(', ']':'[', '}':'{'}

        for c in s:
            if c in matching_open:
                if stack and stack[-1] == matching_open[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return not stack



