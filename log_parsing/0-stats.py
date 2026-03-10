#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics
"""

import sys

def print_stats(total_size, status_counts):
    """Print the file size and status code counts"""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))

if __name__ == "__main__":
    total_size = 0
    status_counts = {}
    line_count = 0
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()
            # Check if the line has at least 9 parts (basic format)
            if len(parts) < 9:
                continue
            # Last two items should be status code and file size
            try:
                status = int(parts[-2])
                size = int(parts[-1])
            except ValueError:
                continue

            # Only count known status codes
            if status in valid_codes:
                status_counts[status] = status_counts.get(status, 0) + 1

            total_size += size

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        pass
    finally:
        if line_count % 10 != 0:
            print_stats(total_size, status_counts)
            