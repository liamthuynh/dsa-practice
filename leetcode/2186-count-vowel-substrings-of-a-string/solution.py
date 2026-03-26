class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        # helper to map each vowel to an index 0..4
       # scan word and find contigous vowel only segments
        # for each segment we:
            # initialize left = start, have = 0, and counts[5] = 0
            # for right from start to end:
                # add word[right] to count; if that vowel count becomes 1, increment have
                # while have == 5:
                    # try to remove word[left] from counts and move left foward
                    # if a vowel count becomes 0, decrement 'have' 
                # add left - start to answer
         # return total 

        vowels = set(['a', 'e', 'i', 'o', 'u'])

        def vidx(c):
            if c == 'a':
                return 0
            if c == 'e':
                return 1
            if c == 'i':
                return 2
            if c == 'o':
                return 3
            return 4
        ans = 0

        n = len(word)

        i = 0

        while i < n:
            while i < n and word[i] not in vowels:
                i = i + 1

            if i >= n:
                break

            start = i

            while i < n and word[i] in vowels:
                i = i + 1

            end = i - 1

            left = start
            counts = [0, 0, 0, 0, 0]

            have = 0 

            right = start 
            while right <= end:
                idx_r = vidx(word[right])
                counts[idx_r] = counts[idx_r] + 1

                if counts[idx_r] == 1:
                    have = have + 1

                while have == 5:
                    idx_l = vidx(word[left])
                    counts[idx_l] = counts[idx_l] - 1

                    if counts[idx_l] == 0:
                        have = have - 1

                    left = left + 1

                ans = ans + ( left - start)

                right = right + 1
        return ans

            
