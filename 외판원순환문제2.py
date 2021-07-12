from itertools import permutations
import sys
input = sys.stdin.readline
n = int(input())
w = [list(map(int,input().split())) for _ in range(n)]
perm = list(range(n))

INT_MAX =2147483647
ans = INT_MAX

for p in list(permutations(perm)):
  if w[p[-1]][p[0]] == 0 : continue
  
  isPossible = True
  costs = 0
  for i in range(n-1):
    if w[p[i]][p[i+1]] == 0 :
      isPossible = False
      break
    else : 
      costs+= w[p[i]][p[i+1]]
      if costs >= ans :
        isPossible=False
        break
  if isPossible == False : continue
  costs+=w[p[-1]][p[0]]
  ans = min(ans,costs)
print(ans)
