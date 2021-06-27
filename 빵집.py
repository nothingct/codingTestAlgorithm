import sys
input = sys.stdin.readline
R, C = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(R)]
visited = [ [False] *C for _ in range(R)]

dx=(-1,0,1)
dy=(1,1,1)

def dfs(x,y):
  visited[x][y]= True
  #마지막 열에 도착한 경우 
  if y == C-1:
    return True
  #아닌 경우 탐색 시작 : 우상단, 오른쪽, 우하단 
  for i in range(3):
    nx,ny= x+dx[i], y+dy[i]
    #탐색 가능 여부 확인 
    if 0<=nx<R and 0<=ny<C:
      if visited[nx][ny] == False and graph[nx][ny]=='.':
        res = dfs(nx,ny)
        if(res):
          return res
  return False

ans = 0
for i in range(R):
  ans+=dfs(i,0)
print(ans)