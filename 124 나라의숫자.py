def solution(n):
    answer = ''
    digit = ("4", "1", "2")
    while n != 0:
        mod = n % 3
        n //= 3
        if mod == 0:
            n -= 1
        answer = digit[mod]+answer
    return answer
