def go(today,profit,lastDay,t,p):
  if today > lastDay: return 0
  if today == lastDay: return profit
  ret = max(go(today+1,profit,lastDay,t,p),go(today+t[today],profit+p[today],lastDay,t,p))
  return ret
n= int(input())
t= [0]*n
p=[0]*n
for i in range(n):
  t[i],p[i]= map(int,input().split())
print(go(0,0,n,t,p))