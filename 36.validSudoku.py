board = [["8", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8",
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


if __name__ == "__main__":
    print(isValidSudoku(board))
