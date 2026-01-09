from collections import deque

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    if m < n and n % 3 != 0:
        print("No")
        continue

    q = deque([n])
    found = False

    while q:
        x = q.popleft()

        if x == m:
            found = True
            break

        if x % 3 == 0:
            q.append(x // 3)
            q.append((x // 3) * 2)

    print("Yes" if found else "No")

