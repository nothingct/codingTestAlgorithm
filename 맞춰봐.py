def check(idx):
  sum=0
  for i in range(idx,-1,-1):
    sum+=ans[i]
    if sign[i][idx]==0:
      if sum !=0 : return False
    elif sign[i][idx] >0:
      if sum<=0: return False
    elif sign[i][idx] <0:
      if sum >=0  :  return False
  return True

def go(idx):
  if idx==n: return True
  if sign[idx][idx]==0:
    ans[idx]=0
    return check(idx) and go(idx+1)
  for i in range(1,11):
    ans[idx] = sign[idx][idx]*i
    if check(idx) and go(idx+1): return True
  return False

n=int(input())
s=input()
sign = [[0]*n for _ in range(n)]
ans=[0]*n
cnt=0
for i in range(n):
  for j in range(i,n):
    if s[cnt]=='0' : sign[i][j] = 0
    elif s[cnt]=='+' :sign[i][j] =1
    else: sign[i][j] = -1
    cnt+=1
go(0)
print(' '.join(map(str, ans)))
