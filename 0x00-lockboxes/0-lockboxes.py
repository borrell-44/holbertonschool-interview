#!/usr/bin/python3

def canUnlockAll(boxes):
    condition = False

    if len(boxes) < 2:
        return True

    for i in range(0, len(boxes) - 1):
        for l in range(0, len(boxes)):
            if (i + 1) in boxes[l] and len(boxes[i]) > 0:
                condition = True
        if condition is False:
            return False
        condition = False
    return True
