from itertools import permutations
n= int(input())
arr = [i for i in range(1,n+1)]

for perm in list(permutations(arr)):
  for num in perm :
    print(num,end=' ')
  print()