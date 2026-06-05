#!/usr/bin/python3
"""
Module qui compte les mots-clés dans les titres des hot posts Reddit
"""
import requests


def count_words(subreddit, word_list, counts=None, after=None):
    """
    Queries Reddit API recursively and counts keyword occurrences in hot titles

    Args:
        subreddit: name of the subreddit to search
        word_list: list of keywords to count
        counts: dictionary accumulating counts (built across recursive calls)
        after: pagination token for the next page of results

    Returns:
        Nothing - prints results directly
    """
    # Initialise le dictionnaire de comptage au premier appel
    if counts is None:
        counts = {}
        for word in word_list:
            w = word.lower()
            counts[w] = counts.get(w, 0)  # gère les doublons dans word_list

    # Construction de l'URL avec pagination
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    params = {"limit": 100}
    if after:
        params["after"] = after

    headers = {"User-Agent": "count_words_script/1.0"}

    # Requête API sans suivre les redirections
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    # Subreddit invalide ou erreur
    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    posts = data.get("children", [])
    next_after = data.get("after", None)

    # Compte les mots-clés dans chaque titre
    for post in posts:
        title = post.get("data", {}).get("title", "").lower()
        # Découpe le titre en mots
        words = title.split()
        for word in words:
            # Nettoie la ponctuation autour du mot
            clean = word.strip("!.,_?;:'\"()[]{}\\/@#$%^&*+=<>~`|-")
            if clean in counts:
                counts[clean] += 1

    # S'il y a une page suivante → on rappelle récursivement
    if next_after:
        count_words(subreddit, word_list, counts, next_after)
    else:
        # Plus de pages → on affiche les résultats
        # Tri : par count décroissant, puis alphabétique croissant
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print("{}: {}".format(word, count))
