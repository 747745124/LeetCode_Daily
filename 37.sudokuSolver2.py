from itertools import permutations
import copy
board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8",
                                                                                                                                                                                                      ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]


def isValidSudoku(board):
    for row in board:
        # check if there are duplicates in the row
        for elem in row:
            if row.count(elem) > 1 and elem != ".":
                return False

    # check if there are duplicates in the column
    for i in range(len(board)):
        column = []
        for j in range(len(board)):
            column.append(board[j][i])

        for elem in column:
            if column.count(elem) > 1 and elem != ".":
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


# def sudokuSolverFail(board):
#     numList = [x for x in range(1, 10)]
#     flag = 0
#     for row in board:
#         for elem in row:
#             if elem == ".":
#                 flag = 1
#                 break
#     if flag:
#         # fill each blank and then check its validity
#         for row in board:
#             for elem in row:
#                 if elem == ".":
#                     for num in numList:
#                         elem = num
#                         if isValidSudoku(board):
#                             return sudokuSolver(board)
#                         continue
#     return board


# # perm = list(permutations(range(1, 10)))
# boardList = []
# numlistList = []


# def sudokuSolverBruteForce(board):
#     newBoard = copy.deepcopy(board)
#     for i in range(0, 9):
#         # each board[i] share the same numlist
#         numList = [str(x) for x in range(1, 10)]
#         for j in range(0, 9):
#             if newBoard[i][j] != ".":
#                 numList.remove(newBoard[i][j])
#                 continue
#         perm = list(permutations(numList))
#         for p in perm:
#             for j in range(0, 9):
#                 for elem in numList:
#                     if newBoard[i][j] == ".":
#                         newBoard[i][j] = elem
#                         numList.remove(elem)
#                         break
#         if(isValidSudoku(newBoard)):
#             return newBoard
#     return False


# numList = [str(x) for x in range(1, 10)]

blank = []


def getBlank(board):
    for i in range(0, 9):
        for j in range(0, 9):
            if board[i][j] == ".":
                blank.append([i, j])
    # end of blanks
    blank.append([-1, -1])


def sudokuSolverBF(board, b):
    if len(blank) == 1:
        return True

    nb = blank[1]
    for num in numList:
        if isValidSudoku(board):
            board[b[0]][b[1]] = num
            blank.remove(b)
            if sudokuSolverBF(board, nb):
                return True
            blank.insert(0, b)
            board[b[0]][b[1]] = '.'
    return False


if __name__ == "__main__":
    getBlank(board)
    b = blank[0]
    sudokuSolverBF(board, b)
    print(board)

    # print(sudokuSolverBF(board))

    # print(perm[0], perm[1])
    # print(perm[0])
