#!/usr/bin/python3
"""Module that calculates rainwater retention between walls."""


def rain(walls):
    """Calculate total rainwater retained between walls.

    Args:
        walls (list): Non-negative integers representing wall heights.

    Returns:
        int: Total amount of rainwater retained.
    """
    if not walls:
        return 0

    n = len(walls)
    total = 0
    max_left = [0] * n
    max_right = [0] * n

    for i in range(1, n):
        max_left[i] = max(max_left[i - 1], walls[i - 1])

    for i in range(n - 2, -1, -1):
        max_right[i] = max(max_right[i + 1], walls[i + 1])

    for i in range(n):
        water = min(max_left[i], max_right[i]) - walls[i]
        if water > 0:
            total += water

    return total
