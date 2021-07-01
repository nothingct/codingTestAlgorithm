n=int(input())
d = [0]*(n+1)
wines =[0] + [int(input()) for _ in range(n)]
d[1] = wines[1]
if n >=2 :
  d[2] = wines[1]+wines[2]
for i in range(3,n+1):
  d[i]= max(d[i-1],d[i-2]+wines[i],d[i-3]+wines[i-1]+wines[i])
print(d[n])