#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount.
"""


def makeChange(coins, total):
    """
    Compute the minimum number of coins needed to make up 'total'.

    Args:
        coins (list): list of the values of the coins available
                       (infinite supply of each).
        total (int): the amount to reach.

    Returns:
        int: fewest number of coins needed to meet total.
             0 if total is 0 or less.
             -1 if total cannot be met with the given coins.
    """
    if total <= 0:
        return 0

    # best[amount] = fewest coins needed to make exactly "amount"
    # start at "infinity" (impossible) for every amount except 0
    best = [0] + [float('inf')] * total

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount and best[amount - coin] + 1 < best[amount]:
                best[amount] = best[amount - coin] + 1

    return best[total] if best[total] != float('inf') else -1
