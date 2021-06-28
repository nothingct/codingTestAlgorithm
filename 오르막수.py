mod  = 10007
n = int(input())
# d[n][m]: 1번째 수 ~n번째 수 를 채울 때, n번째 수가 m 일때의 오르막수의 경우의 수.
d = [ [0] *10 for _ in range(n+1)]
# 초기 값 d[1][m] = 1 한 자리 오르막수 는 모두 자기자신을 끝으로 가질 수 밖에없다.
for i in range(10):
  d[1][i]=1
for i in range(2,n+1):
  for j in range(10):
    for k in range(j+1):
      # 점화식: d[i][j]: BY 연결의 조건 i번째 자리의 수가 j일 때의 오르막 수는
      # i-1번째 자리의 수가 j보다 작거나 같은 오르막 수들만 연결이 가능하다
      d[i][j] += d[i-1][k]
      d[i][j]%=mod
      # 정답: d[n][1]~d[n][9] 의 합
print(sum(d[n])%mod)
