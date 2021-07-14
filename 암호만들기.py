def isValidPW(pw):
  mo=0 
  ja=0
  for ch in pw:
    if ch in 'aeiou': mo+=1
    else: ja+=1
  return mo >=1 and ja >=2

def go(index,alpha,pw,n):
  if len(pw)==n:
    if isValidPW(pw):
      print(pw)
    return
  if index == len(alpha) : return 
  go(index+1,alpha,pw+alpha[index],n)
  go(index+1,alpha,pw,n)

n,m = map(int,input().split())
alpha = input().split()
alpha.sort()
go(0,alpha,"",n)