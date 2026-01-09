from collections import deque

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]

    ans = 0
    dirs = [(1,0), (-1,0), (0,1), (0,-1)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] > 0:
                q = deque()
                q.append((i, j))
                tempAns = grid[i][j]
                grid[i][j] = 0

                while q:
                    x, y = q.popleft()
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] > 0:
                            tempAns += grid[nx][ny]
                            q.append((nx, ny))
                            grid[nx][ny] = 0

                ans = max(ans, tempAns)

    print(ans)
