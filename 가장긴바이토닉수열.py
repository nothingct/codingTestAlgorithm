n = int(input())
a = list(map(int,input().split()))
lis = [1]*n
lds = [1]*n
for i in range(n):
  for j in range(i):
    if a[i] > a[j] and lis[i] < lis[j]+1:
      lis[i] = lis[j]+1
for i in range(n-1,-1,-1):
  for j in range(i+1,n):
    if a[i] > a[j] and lds[i] <lds[j]+1:
      lds[i]= lds[j]+1
bitonic = [lis[i]+lds[i]-1 for i in range(n)]
print(max(bitonic))