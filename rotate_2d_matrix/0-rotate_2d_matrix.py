#!/usr/bin/python3
"""
Module that rotates an n x n 2D matrix 90 degrees clockwise in-place.
"""


def rotate_2d_matrix(matrix):
    """
    Rotate an n x n matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of lists): The matrix to rotate.

    Returns:
        None
    """
    n = len(matrix)

    # Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for row in matrix:
        row.reverse()
