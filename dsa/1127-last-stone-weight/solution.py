class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            heaviest = heapq.heappop(stones)
            second_heavy = heapq.heappop(stones)
            if second_heavy > heaviest: # because negative
                heapq.heappush(stones, heaviest - second_heavy) # to make sure 'stones' still negative to compute others

        stones.append(0) # to make sure in case the list empty beacuse all stones smashed
        return abs(stones[0]) # make sure to turn it back normal

        # better return syntax:
        # return -stones[0] if stones else 0
