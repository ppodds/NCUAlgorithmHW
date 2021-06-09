# 這題用C++寫實在太浪費生命了

N = int(input())

for _ in range(N):
    cardNum = int(input().replace(' ', ''))
    even = str(cardNum)[::2]
    odd = str(cardNum)[1::2]
    sum = 0
    for c in even:
        tmp = int(c) * 2
        while tmp != 0:
            sum += tmp % 10
            tmp //= 10
    for c in odd:
        sum += int(c)
    if str(sum)[-1] == '0':
        print('Valid')
    else:
        print('Invalid')
