Dt = int(input())

INF = 10**18

for _ in range(t):
    n = int(input())
    
    both = INF
    only1 = INF
    only2 = INF
    
    for _ in range(n):
        m, s = input().split()
        m = int(m)
        
        if s == "11":
            both = min(both, m)
        elif s == "10":
            only1 = min(only1, m)
        elif s == "01":
            only2 = min(only2, m)
    
    ans = min(both, only1 + only2)
    
    if ans >= INF:
        print(-1)
    else:
        print(ans)
