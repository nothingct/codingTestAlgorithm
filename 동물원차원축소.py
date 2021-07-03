n = int(input())
MOD =9901
d = [0]*(n+1)
s = [0]*(n+1)

d[0]=1
s[0]=d[0]

d[1]=2
s[1]=s[0]+d[1]

for i in range(2,n+1):
  d[i] = d[i-1]+2*s[i-2]
  s[i]= s[i-1]+d[i]
  d[i]%=MOD
  s[i]%=MOD
print(s[n])