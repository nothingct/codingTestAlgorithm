MAX = 1000000
MOD = 1000000009
d=[0]*(MAX+1)
d[0]=1
d[1]=1
d[2]=2
for i in range(3,MAX+1):
  d[i] = d[i-1]+d[i-2]+d[i-3]
  d[i]%=MOD
t= int(input())
for _ in range(t):
  n=int(input())
  print(d[n])
