n=int(input())
a=list(map(int,input().split()))
d=[0]*n
for i in range (n):
  d[i]= a[i]
  for j in range(i):
    if a[i] > a[j] and d[i] < d[j]+a[i]:
      d[i]=d[j]+a[i]
print(max(d))