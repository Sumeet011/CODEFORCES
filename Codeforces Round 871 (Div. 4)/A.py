T = int(input())

while T > 0:
    S = input().strip()
    L = "codeforces"
    Ans = 0

    for i in range(len(L)):
        if S[i] != L[i]:
            Ans += 1

    print(Ans)
    T -= 1
