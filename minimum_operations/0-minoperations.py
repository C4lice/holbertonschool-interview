#!/usr/bin/python3
"""
Minimum operations to reach n H characters
"""


def minOperations(n):
    """
    Calculate the minimum number of operations
    needed to obtain exactly n H characters.

    Args:
        n (int): target number of H characters

    Returns:
        int: minimum number of operations
    """

    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
