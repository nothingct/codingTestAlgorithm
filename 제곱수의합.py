n = int(input())
d = [0]*(n+1)
# O(N *√N)
for i in range(1, n+1):
    #d[i]: i를 제곱수의 합으로 표현할 때 그 항의 최소개수
    #초기값: 모든 수 i는 1 ^ 2 를 i 번 더함으로 표현할 수 있다.
    d[i] = i
    #d[i]: ㅁ + ㅁ + ㅁ + ㅁ + x ^ 2 = > (x ^ 2 <= i) = >min(d[i-x ^ 2]+1)
    j = 1
    while j*j <= i:
        if d[i] > d[i-j*j]+1:
            d[i] = d[i-j*j]+1
        j += 1
print(d[n])
