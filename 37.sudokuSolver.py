import timeit
import numba as nb


class Solution:
    blank = []

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for row in board:
            if not self.isValid(row):
                return False

        for col in zip(*board):
            if not self.isValid(col):
                return False

        for i in (0, 3, 6):
            for j in (0, 3, 6):
                square = [board[x][y]
                          for x in range(i, i + 3) for y in range(j, j + 3)]
                if not self.isValid(square):
                    return False

        return True

    def isValid(self, s):
        unit = [i for i in s if i != '.']
        return len(unit) == len(set(unit))

    def getBlank(self, board):
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] == ".":
                    self.blank.append([i, j])
        # end of blanks
        self.blank.append([-1, -1])

    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        self.getBlank(board)
        b = self.blank[0]
        self.sudokuSolverBF(board, b)

    def sudokuSolverBF(self, board, b):
        if len(self.blank) == 1:
            return True

        nb = self.blank[1]
        for num in [str(x) for x in range(1, 10)]:
            if self.isValidSudoku(board):
                board[b[0]][b[1]] = num
                self.blank.remove(b)
                if self.sudokuSolverBF(board, nb):
                    return True
                self.blank.insert(0, b)
                board[b[0]][b[1]] = '.'
        return False

        # check if there are duplicates in the 3x3 grid
        for i in range(0, len(board), 3):
            for j in range(0, len(board), 3):
                grid = []
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        grid.append(board[k][l])

                for elem in grid:
                    if grid.count(elem) > 1 and elem != ".":
                        return False
        return True


if __name__ == "__main__":
    board = [[".", ".", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8",
                                                                                                                                                                                                          ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    sol = Solution()
    start = timeit.default_timer()
    sol.solveSudoku(board)
    stop = timeit.default_timer()
    print(stop - start)
    print(board)
