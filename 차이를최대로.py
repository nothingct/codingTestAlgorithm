from itertools import permutations
def calDiffSum(a):
  ret = 0
  for i in range(1,len(a)):
    ret+= abs(a[i]-a[i-1])
  return ret
n=int(input())
arr = list(map(int,input().split()))
arr.sort()
ans =0
for perm in list(permutations(arr)):
  ans = max(ans,calDiffSum(perm))
print(ans)