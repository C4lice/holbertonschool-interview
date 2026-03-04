#!/usr/bin/python3
def canUnlockAll(boxes):
    n = len(boxes)
    opened = set([0])   # boîte 0 déjà ouverte
    stack = [0]         # pile pour explorer

    while stack:
        current = stack.pop()

        for key in boxes[current]:
            if key < n and key not in opened:
                opened.add(key)
                stack.append(key)

    return len(opened) == n
