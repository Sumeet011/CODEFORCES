t = int(input().strip())
for _ in range(t):
    s, k, m = map(int, input().strip().split())

    effective = min(s, k)

    if s == k:
        # same as effective == s
        elapsed = m % k
        print(max(0, effective - elapsed))

    elif s < k:
        if m >= k:
            elapsed = m % k
            print(max(0, effective - elapsed))
        else:
            # no flip yet
            print(max(0, s - m))

    else:  # s > k
        if m >= k:
            elapsed = m % k
            print(max(0, effective - elapsed))
        else:
            print(max(0, s - m))
