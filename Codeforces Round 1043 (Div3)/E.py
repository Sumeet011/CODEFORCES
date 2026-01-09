import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    # sort descending (important)
    a.sort(reverse=True)
    b.sort(reverse=True)

    # prefix sums
    PA = [0] * (n + 1)
    PB = [0] * (m + 1)

    for i in range(n):
        PA[i + 1] = PA[i] + a[i]
    for i in range(m):
        PB[i + 1] = PB[i] + b[i]

    for _ in range(q):
        x, y, z = map(int, input().split())

        ans = 0

        # i = cards from A
        lo = max(0, z - y)
        hi = min(z, x, n)

        for i in range(lo, hi + 1):
            if z - i <= m:
                ans = max(ans, PA[i] + PB[z - i])

        print(ans)
