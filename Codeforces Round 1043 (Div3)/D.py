import sys
input = sys.stdin.readline

def sum_digits_upto(n):
    """returns sum of digits from 1 to n"""
    cnt = [0] * 10
    factor = 1

    while factor <= n:
        lower = n % factor
        current = (n // factor) % 10
        higher = n // (factor * 10)

        for d in range(10):
            if d != 0:
                if current > d:
                    cnt[d] += (higher + 1) * factor
                elif current == d:
                    cnt[d] += higher * factor + lower + 1
                else:
                    cnt[d] += higher * factor
            else:
                if higher != 0:
                    if current > 0:
                        cnt[0] += higher * factor
                    elif current == 0:
                        cnt[0] += (higher - 1) * factor + lower + 1

        factor *= 10

    # convert frequency → sum
    return sum(d * cnt[d] for d in range(10))


t = int(input())
for _ in range(t):
    k = int(input())

    Ans = 0
    digits = 1
    count = 9

    # find digit-length block
    while k > digits * count:
        Ans += sum_digits_upto(10**digits - 1) - sum_digits_upto(10**(digits - 1) - 1)
        k -= digits * count
        digits += 1
        count *= 10

    # process remaining
    full = k // digits
    rem = k % digits

    start = 10**(digits - 1)

    if full > 0:
        Ans += sum_digits_upto(start + full - 1) - sum_digits_upto(start - 1)

    if rem > 0:
        num = start + full
        s = str(num)
        for i in range(rem):
            Ans += int(s[i])

    print(Ans)
