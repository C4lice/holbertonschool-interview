#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics.
"""

import sys

VALID_CODES = ["200", "301", "400", "401", "403", "404", "405", "500"]


def print_stats(total_size, status_counts):
    """print all the stats"""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def main():
    total_size = 0
    line_count = 0
    status_counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 7:
                continue

            status = parts[-2]
            size = parts[-1]
            if status in VALID_CODES:
                status_counts[status] += 1
            try:
                total_size += int(size)
            except ValueError:
                pass

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        pass
    print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
