n= int(input())
d=[0]*(n+1)
d[0]=1
for i in range(2,n+1,2):
  d[i]= 3 *d[i-2]
  for j in range(i-4,-1,-2):
    d[i]+=2*d[j]
print(d[n])