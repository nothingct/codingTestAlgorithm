n,k= map(int,input().split())
mod = 1000000000
d=[ [0]*(n+1) for _ in range(k+1)]
# d[k][i]: 0~i까지의 정수 K개를 더해서 그 합이 i 이 되는 경우의수
# 초기값: d[i][1] = 1, 1개의 정수만으로 i를 표현하려면 자기자신 말고는 불가능.by 반복문 -> 초기값보장됨
d[0][0] = 1
for i in range(1,k+1):
  for j in range(n+1):
    for l in range(j+1):
      # 점화식: d[k][i] = sum(d[k-1][i-j])[j <= i]
      d[i][j]+= d[i-1][j-l];
      d[i][j]%=mod
print(d[k][n])

  