n = int(input())
arr= list(map(int,input().split()))
conSumEnd=[0]*n
conSumBegin=[0]*n
conSumEnd[0]=arr[0];
for i in range(1,n):
  conSumEnd[i]=max(conSumEnd[i-1]+arr[i],arr[i])
conSumBegin[n-1]=arr[n-1]
for i in range(n-2,-1,-1):
  conSumBegin[i]=max(conSumBegin[i+1]+arr[i],arr[i])
ans = max(conSumEnd)
for i in range(1,n-1):
  if ans < conSumEnd[i-1]+conSumBegin[i+1]:
    ans= conSumEnd[i-1]+conSumBegin[i+1]
print(ans)