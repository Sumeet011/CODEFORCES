t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    a = input().strip()

    m = int(input().strip())
    b = input().strip()
    c = input().strip()
    P=""
    A=""
    for i in range(m):
        if c[i]=='D':
            a+=b[i]
        else:
            T=b[i]+a
            a=T
    print(a)
