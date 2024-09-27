import heapq
class Solution:
    #dijkstra
    def min_ones_path(self,grid):
        rows, cols = len(grid), len(grid[0])
        # Initialize the cost matrix with infinity
        cost = [[float('inf')] * cols for _ in range(rows)]
        cost[0][0] = grid[0][0]

        # Priority queue for Dijkstra's algorithm
        heap = [(cost[0][0], 0, 0)]  # (current cost, row, col)

        # Directions: up, down, left, right
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        while heap:
            curr_cost, row, col = heapq.heappop(heap)

            # If we reached the bottom-right cell, return the cost
            if row == rows - 1 and col == cols - 1:
                return curr_cost

            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc

                if 0 <= new_row < rows and 0 <= new_col < cols:
                    new_cost = curr_cost + grid[new_row][new_col]
                    if new_cost < cost[new_row][new_col]:
                        cost[new_row][new_col] = new_cost
                        heapq.heappush(heap, (new_cost, new_row, new_col))

        return 0

    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        return self.min_ones_path(grid)>=health