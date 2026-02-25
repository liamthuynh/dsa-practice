class Solution:
    def reverseWords(self, s: str) -> str:
        
        arr = []
        n = len(s)
        i = 0

        while i < n:
            while i < n and s[i] == ' ':
                i = i + 1
            if i >= n:
                break
            
            if len(arr) > 0:
                arr.append(' ')
            
            while i < n and s[i] != ' ':
                arr.append(s[i])
                i = i + 1

        def reverse_range(left: int, right: int):
            while left < right: 
                temp = arr[left]
                arr[left] = arr[right]
                arr[right] = temp
                left = left + 1
                right = right - 1

        if len(arr) == 0:
            return ''

        reverse_range(0, len(arr) - 1)

        start = 0
        j = 0 
        while j <= len(arr):
            if j == len(arr) or arr[j] == ' ':
                reverse_range(start, j - 1)
                start = j + 1
            j = j + 1

        return "".join(arr)
