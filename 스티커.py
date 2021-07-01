t = int(input())
for _ in range(t):
  n = int(input())
  # zip 사용방법 익히기.
  sticker1 = [0]+list(map(int, input().split()))
  sticker2 = [0]+list(map(int, input().split()))
  sticker = list(zip(sticker1,sticker2))
  d = [[0]*3 for _ in range(n+1)]
  for i in range(1, n+1):
    d[i][0] = max(d[i-1])
    d[i][1] = max(d[i-1][0], d[i-1][2])+sticker[i][0]
    d[i][2] = max(d[i-1][0], d[i-1][1]) + sticker[i][1]
  ans = max(d[n])
  print(ans)
