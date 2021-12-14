import re
from itertools import combinations
from itertools import product
ops = ['+', '-', '*', '']


class Solution:
    # description: given a numList and a target num,
    # return all possibilities of num operation expression resulting the target value.
    # only use + - and *
    # the numList is given in the form of string, split it yourself
    def addOperatorsBF(self, num, target):
        posList = self.genPos(len(num))
        exprList = []
        posNewList = []
        for posCombo in posList:
            newNum = num
            for pos in posCombo:
                for coord in pos:
                    if(not len(pos)):
                        break
                    if(newNum[:coord] == '' or newNum[coord:] == ''):
                        break
                    if(((newNum[: coord][0] == '0') and len(newNum[: coord]) > 1 and newNum[: coord].isdigit()) or ((newNum[coord:][0] == '0') and len(newNum[coord:]) > 1) and newNum[coord:].isdigit()):
                        break
            posNewList.append(posCombo)

        for posCombo in posNewList:
            for pos in posCombo:
                opList = list(product(ops, repeat=len(pos)))
                newNum = num
                # say, we have a pos of (1,2,3), it could be have 8 possible expressions
                # it's crucial to insert in reverse order
                possible = list(product(posCombo, opList))
                length = len(pos)
                # print(possible)
                for i in possible:
                    posList, opL = i
                    newNum = num
                    for j in range(length).__reversed__():
                        if(newNum[: posList[j]] == '' or newNum[posList[j]:] == ''):
                            break
                        if(((newNum[: posList[j]][0] == '0') and len(newNum[: posList[j]]) > 1 and newNum[: posList[j]].isdigit()) or ((newNum[posList[j]:][0] == '0') and len(newNum[posList[j]:]) > 1) and newNum[posList[j]:].isdigit()):
                            break

                        newNum = newNum[: posList[j]] + \
                            opL[j]+newNum[posList[j]:]
                    if(self.isValid(newNum)):
                        exprList.append(newNum)

        resList = []
        for expr in set(exprList):
            if expr.isdigit():
                if expr[0] == '0':
                    continue

            res = eval(expr)
            if res == target:
                resList.append(expr)

        return resList

 # given a length of string, generate all possible slots combinations to place operators

    def genPos(self, length):
        res = []
        for i in range(length):
            res.append(list(combinations(range(length), i)))
        return res

# check expression contains leading zero
    def isValid(self, expr):
        elemList = re.findall(r"[\w']+", expr)
        for elem in elemList:
            if(elem.startswith('0') and len(elem) > 1):
                return False
        return True

    def addOperatorsBFCleansed(self, num, target):
        combo = list(product(ops, repeat=len(num)-1))
        resList = []
        for opl in combo:
            newNum = num
            for idx in range(len(opl)).__reversed__():
                '''check cases for leading zero'''
                idx += 1
                if(((newNum[idx:][0] == '0') and len(newNum[idx:]) > 1) and newNum[idx:].isdigit()):
                    break
                newNum = newNum[:idx] + opl[idx-1] + newNum[idx:]

            if(not self.isValid(newNum)):
                continue

            if newNum.isdigit():
                if newNum[0] == '0':
                    continue

            if eval(newNum) == target:
                resList.append(newNum)

        return resList


if __name__ == '__main__':
    sol = Solution()
    test = "123456789"
    target = 45
    print(len(sol.addOperatorsBFCleansed(test, target)))

'''
((newNum[: idx][0] == '0') and len(newNum[: idx]) > 1 and newNum[: idx].isdigit() and idx == 1) or 
'''
