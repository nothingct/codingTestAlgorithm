n = int(input())
houses = [(0,0,0)]+[tuple(map(int,input().split())) for _ in range(n)]
d = [ [0]*3 for _ in range(n+1)]
MAX = 1000
ans = MAX*MAX +1 #절대 나올 수 없는 최댓값(각 집의 최대비용이 1000, 집의 최대개수가 1000이므로 )
#1번째 집의 색을 R,G,B 로 고정(0,1,2)
for i in range(3):
  d[1][0] =MAX*MAX+1
  d[1][1] = MAX*MAX+1
  d[1][2]=MAX*MAX+1
  d[1][i] = houses[1][i]
  #이후 2번째~ n번째 까지의 비용 최솟값은 RGB거리 문제와 동일한 점화식으로 푼다. 
  for j in range(2,n+1):
    d[j][0] = min(d[j-1][1], d[j-1][2])+houses[j][0]
    d[j][1] = min(d[j-1][0], d[j-1][2])+houses[j][1]
    d[j][2] = min(d[j-1][0], d[j-1][1])+houses[j][2]
  #이후 정답의 후보를 찾을 때, n번째 집이 1번째 집의 색깔 즉 i와 같은 경우는 제외한다.
  for j in range(3):
    if i == j :
      continue
    ans = min(ans,d[n][j])
#정답을 출력
print(ans)