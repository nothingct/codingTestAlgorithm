MOD = 1000000000
n, m = map(int, input().split())
d= [0]*(n+1)
d[0]=1
for i in range(m):
  for j in range(1,n+1):
    d[j]+=d[j-1]
    d[j]%=MOD
print(d[n])