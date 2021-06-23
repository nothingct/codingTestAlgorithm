def solutions(s):
  #정답의 마지노선 : 문자열의 길이, 즉 압축이 안된 경우를 초기값 
  answer = len(s) 
  #1개 단위부터 ~ 문자열의 반절까지 압축 단위 를 증가시키며 시작
  for parseLen in range(1,len(s)//2+1):
    compressed = ""
    parsed= s[0:parseLen]
    count =1
    #단위(parseLen)만큼 증가시키며 이전 문자열과 비교 
    for i in range(parseLen,len(s), parseLen):
      #parsed 문자열과 동일하면 count++ 
      if parsed == s[i:i+parseLen]:
        count+=1
      #다른 문자열이 나왔다면 현재까지 압축된 정보 기록,초기화
      else:
        compressed+= str(count)+parsed if count >=2 else parsed
        parsed = s[i:i+parseLen] #다시 parsed문자열 다음으로 초기화
        count=1
    #남아있는 문자열 처리 
    compressed+= str(count)+parsed if count >=2 else parsed
    #정답 후보찾기 
    answer = min(answer, len(compressed))
  return answer