t = int(input().strip())

for _ in range(t):
    a = int(input().strip())
    S = str(a)
    n = len(S)

    Ans = []

    for i in range(n - 1):  # skip last index
        k = 10 ** (n - i - 1) + 1
        if a % k == 0:
            Ans.append(a // k)

    if Ans:
        print(len(Ans))
        print(" ".join(map(str, Ans)))
    else:
        print(0)
