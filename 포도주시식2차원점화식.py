n = int(input())
wines = [0] + [int(input()) for _ in range(n)]
d = [[0]*(3)for _ in range(n+1)]
for i in range(1, n+1):
  d[i][0] = max(d[i-1])
  d[i][1] = d[i-1][0]+wines[i]
  d[i][2] = d[i-1][1]+wines[i]
ans = max(d[n])
print(ans)
