#!/usr/bin/python3
import sys


def is_valid(positions, row, col):
    for qx, qy in positions:
        if qy == col:
            return False
        if abs(qx - row) == abs(qy - col):
            return False
    return True


def backtrack(row, positions, N):
    if row == N:
        print(positions)
        return

    for col in range(N):
        if is_valid(positions, row, col):
            positions.append([row, col])
            backtrack(row + 1, positions, N)
            positions.pop()


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    backtrack(0, [], N)


if __name__ == "__main__":
    main()
