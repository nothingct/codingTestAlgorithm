n=int(input())
a=list(map(int,input().split()))
d=[1]*n
s=[-1]*n
for i in range(n):
  for j in range(i):
    if a[j] < a[i] and d[i] <d[j]+1:
      d[i]= d[j]+1
      s[i]=j
ans = max(d)
# enumerate 는 tuple 을 반환하므로 튜플은 두 개-> 이중 idx 만 사용하므로[0] 을 붙여서 idx만 가져와야한다.
idx = [i for i,x in enumerate(d) if x== ans][0] 
print(ans)
def printArray(idx):
  if idx == -1:
    return
  printArray(s[idx])
  print(a[idx],end=' ')
printArray(idx)
print()