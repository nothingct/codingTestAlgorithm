MOD = 1000000000
#d[n][m]: 0~n까지의 정수 m개를 더해서 그 합이 n이 되는 경우의 수
n,m= map(int,input().split())
d= [[0]*(n+1) for _ in range(m+1)]
d[0][0] = 1
for i in range(1,m+1):
  for j in range(n+1):
    d[i][j] = d[i-1][j]
    if j>= 1 :
      d[i][j]+= d[i][j-1]
    d[i][j]%= MOD
print(d[m][n])
