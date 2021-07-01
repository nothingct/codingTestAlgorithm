n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]
d = [[0]*n for i in range(n)]
d[0][0] = triangle[0][0]
for i in range(1, n):
    for j in range(0, i+1):
        d[i][j] = d[i-1][j] + triangle[i][j]
        if j-1 >= 0 and d[i][j] < d[i-1][j-1] + triangle[i][j]:
            d[i][j] = d[i-1][j-1] + triangle[i][j]
print(max(d[n-1]))
