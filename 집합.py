import sys 
input =sys.stdin.readline
print=sys.stdout.write
m=int(input())
s=0
for _ in range(m):
  cmd,*num =input().split()
  if len(num) >0 : x=int(num[0])-1#비트연산을 위해 1감소
  
  if cmd == "add":
    s |= (1 << x)
  elif cmd == "remove":
    s &= ~(1<<x)
  elif cmd =="check":
    ret = s&(1<<x)
    if ret > 0: print("1\n")
    else : print("0\n")
  elif cmd == "toggle":
    s ^=(1<<x)
  elif cmd=="all":
    s= (1<<20)-1
  elif cmd=="empty":
    s=0
  
