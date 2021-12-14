import operator


class Solution:
    def mergeTwoLists(self, l1, l2):
        nodeList = []
        if l1 is not None:
            while(l1.next is not None):
                nodeList.append(l1)
                l1 = l1.next
            nodeList.append(l1)

        if l2 is not None:
            while(l2.next is not None):
                nodeList.append(l2)
                l2 = l2.next
            nodeList.append(l2)

        if(len(nodeList) > 0):
            nodeList.sort(key=operator.attrgetter('val'))

            for i in range(len(nodeList)-1):
                nodeList[i].next = nodeList[i+1]

            nodeList[-1].next = None

            return nodeList[0]

        return None
