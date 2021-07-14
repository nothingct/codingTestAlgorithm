def go(index,first,second):
  if len(first) > n//2 : return -1
  if len(second) > n//2: return -1
  if index==n:
    totalStat1= 0
    totalStat2=0
    for i in range(n//2):
      for j in range(n//2):
        totalStat1+= stat[first[i]][first[j]]
        totalStat2+= stat[second[i]][second[j]]
    return abs(totalStat1-totalStat2)
  ret =-1
  totalStat1= go(index+1,first+[index],second)
  if ret == -1 or totalStat1!=-1 and ret > totalStat1:
    ret= totalStat1
  totalStat2= go(index+1,first,second+[index])
  if ret == -1 or totalStat2 != -1 and ret > totalStat2:
    ret = totalStat2
  return ret
n=int(input())
stat = [list(map(int,input().split())) for _ in range(n)]
print(go(0,[],[]))
