n=int(input())
ops = input().split()
visited = [False]*10
arr= [ [i for i in range(9,-1,-1)], [i for i in range(10)]]
isEnd =False
#isPossible(idx) : idx 번째 수와 idx-1 번째 수를 idx-1번째 부등호로 비교한 결과를 반환.
def isPossible(x,y,idx):
  if ops[idx-1] =='<' : return x<y
  else : return x>y

#go(idx,op) : idx번째의 수를 arr[[op][i]] 번째 수로 채울 지 안 채울 지 결정하는 DFS
def go(idx,op,num):
  global isEnd
  if idx==n+1:
    print(num)
    isEnd = True
    return
  # print(num)
  for i in range(10):
    if visited[arr[op][i]]==True : continue
    if isEnd==True: break
    if idx==0 or isPossible(num[idx-1],str(arr[op][i]),idx):
      visited[arr[op][i]] = True
      go(idx+1,op,num+str(arr[op][i]))
      visited[arr[op][i]]= False

go(0,0,'')
for i in range(10):
  visited[i]=False
isEnd=False
# print("2차")
go(0,1,'')
