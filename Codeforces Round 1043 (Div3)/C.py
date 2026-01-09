import sys
input = sys.stdin.readline

def solve(n, k):
    cnt = [0] * 40
    temp = n
    min_picks = 0

    # base-3 representation
    i = 0
    while temp:
        cnt[i] = temp % 3
        min_picks += cnt[i]
        temp //= 3
        i += 1

    if min_picks > k:
        return -1

    need = k - min_picks  # extra picks needed

    # greedy split from high to low
    for i in range(39, 0, -1):
        if cnt[i] == 0:
            continue

        # each split gives +2 picks
        can_split = min(cnt[i], need // 2)
        if can_split == 0:
            continue

        cnt[i] -= can_split
        cnt[i - 1] += 3 * can_split
        need -= 2 * can_split

        if need == 0:
            break

    # compute cost
    ans = 0
    for i in range(40):
        if cnt[i]:
            if i == 0:
                ans += cnt[i] * 3
            else:
                ans += cnt[i] * (3 ** (i + 1) + i * 3 ** (i - 1))

    return ans


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    print(solve(n, k))
