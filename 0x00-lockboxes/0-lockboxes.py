#!/usr/bin/python3

"""You have n number of locked boxes in front of you. Each 
box is numbered sequentially from 0 to n - 1 and each 
box may contain keys to the other boxes.""" 

def canUnlockAll(boxes):
    """Determines if all boxes can be open"""

    condition = False

    if len(boxes) < 1:
        return True
    print(len(boxes))

    for i in range(0, len(boxes) - 1):
        for l in range(0, len(boxes)):
            if (i + 1) in boxes[l] and len(boxes[i]) > 0:
                print(i + 1)
                condition = True
        if condition is False:
            return False
        condition = False
    return True