def next_permutation(a, n):
  i= n-1
  while i > 0 and a[i-1] >= a[i]: i-=1
  if i <= 0 : return False
  j = n -1
  while j >= i and a[j] <= a[i-1]: j-=1
  a[i-1],a[j] = a[j],a[i-1]
  j= n-1
  while i < j : 
    a[i],a[j] = a[j],a[i]
    i+=1
    j-=1
  return True

n = int(input())
arr = list(map(int,input().split()))
if next_permutation(arr,n):
  for i in range(n):
    print(arr[i],end=' ')
else: 
  print(-1)
print()
