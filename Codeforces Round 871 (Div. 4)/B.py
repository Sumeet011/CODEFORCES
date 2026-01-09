t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    L = 0
    Ans = 0

    for c in a:
        if c == 0:
            L += 1
            Ans = max(Ans, L)
        else:
            L = 0

    print(Ans)