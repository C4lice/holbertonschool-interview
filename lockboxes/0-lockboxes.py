#!/usr/bin/python3
"""
Module contenant la fonction canUnlockAll
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.

    :param boxes : liste de listes contenant des clés
    :return : True si toutes les boîtes peuvent être ouvertes, False sinon
    """
    n = len(boxes)

    # Set pour garder les boîtes déjà ouvertes
    opened = set([0])

    # Pile pour parcourir les boîtes (DFS)
    stack = [0]

    while stack:
        current_box = stack.pop()

        for key in boxes[current_box]:
            # Vérifie que la clé correspond à une boîte existante
            if key < n and key not in opened:
                opened.add(key)
                stack.append(key)

    return len(opened) == n
