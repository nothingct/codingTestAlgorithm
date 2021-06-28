n = int(input())
houses = [0, 0, 0] + [tuple(map(int, input().split())) for _ in range(n)]
d = [[0, 0, 0] for _ in range(n+1)]
for i in range(1, n+1):
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + houses[i][0]
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + houses[i][1]
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + houses[i][2]
print(min(d[n][0],d[n][1],d[n][2]))
